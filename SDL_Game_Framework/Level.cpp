#include "Level.h"

Level::Level(Character *player)
	: m_char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), m_level_trigger(NULL), m_player(player),
	m_timer(new Game_Time()), m_current_time(0), m_play_time(0), m_encounter_gap(0.5), m_last_encounter(0), m_level_number(-1),
	m_area_offset(55)
{
	m_char_fac = new Character_Factory_Implementation();
	m_pickup_fac = new Pick_Objects_Factory_Implementation();
	m_weapon_fac = new Weapon_Factory_Implementation();
}

Level::~Level()
{
	delete m_char_fac;
	m_char_fac = NULL;

	delete m_pickup_fac;
	m_pickup_fac = NULL;

	delete m_weapon_fac;
	m_weapon_fac = NULL;

	for (auto &a : m_areas)
	{
		delete a;
		a = NULL;
	}
	m_areas.clear();

	for (auto &e : m_enemies)
	{
		delete e;
		e = NULL;
	}
	for (auto &n : m_npcs)
	{
		delete n;
		n = NULL;
	}
	m_enemies.clear();
	m_npcs.clear();

	delete m_level_trigger;
	m_level_trigger = NULL;
}

int Level::get_level_number() //return the number of the current level
{
	return m_level_number;
}

bool Level::Run_Level_Logic(float xAmount, float yAmount) //run through the level logic using currently loaded level values
{
	bool should_close = false; //has player lost all their lives and should close the game
	m_play_time = m_timer->Seconds_Since_Start(); //update the current play time, this is used to place a gap between attacks

	Move_All(xAmount, yAmount); //move level using movement decided in play_splash

	should_close = Perform_Enemy_Encounter(); //interact with any collided enemies
	Perform_Coin_Collision(); //pick up any collided coins
	Perform_Weapon_Collision(); //pick up any collided weapons
	Perform_NPC_Encounter(); //interact with any collided npcs

	if (m_pickables.size() == 0) //if all coins have been collected make the level trigger visible
	{
		m_level_trigger->set_visibility(true);
	}

	return should_close;
}

bool Level::Perform_Enemy_Encounter()
{
	for (size_t e = 0; e < m_enemies.size(); e++) //iterate through level enemies
	{
		if (m_enemies[e] != NULL) //if the enemy exists
		{
			if (m_enemies[e]->bb_collision(m_player)) //if enemy has collided with player
			{
				if (m_play_time > m_last_encounter + m_encounter_gap) //if there has been enough time since the last collision
				{
					m_player->Attack(m_enemies[e]); //have the player deal damage to the enemy
					m_enemies[e]->Attack(m_player); //have the enemy deal damage to the player

					if (!m_enemies[e]->Check_Alive()) //check if the enemies health is greater than 0, if it isn't:
					{
						delete m_enemies[e]; //delete the enemy
						m_enemies[e] = NULL; //set enemy memory position to NULL
					}

					if (!m_player->Check_Alive()) //check if the player health is greater than 0, if it isn't:
					{
						if (m_player->get_lives() > 1) //check if the player has any lives left if it does
						{
							Reset_All_Positions(); //reset the position of all level elements (respawn)
							m_player->set_lives(m_player->get_lives() - 1); //decrement the number of lives the player has
						}
						else //if the player has no lives left
						{
							return true; //return that the game should be over
						}
					}

					m_last_encounter = m_play_time; //set the time of the last encounter for checking during the next encounter
				}
			}
		}
	}
	return false; //return that the game should not be over
}

void Level::Perform_Coin_Collision()
{
	for (size_t p = 0; p < m_pickables.size(); p++) //iterate through the all the pickable (non-weapon) objects
	{
		if (m_pickables[p] != NULL && m_player->bb_collision(m_pickables[p])) //if the pickable collides
		{
			m_player->set_score(m_player->get_score() + m_pickables[p]->get_value()); //increment score by pickables value
			delete m_pickables[p]; //delete the pickable
			m_pickables[p] = NULL;
			m_pickables.erase(m_pickables.begin() + p); //we erase this vector element because we use the m_pickables size to determine visibility
			//of the level trigger
			break;
		}
	}
}

void Level::Perform_Weapon_Collision()
{
	for (size_t w = 0; w < m_weapons.size(); w++) //iterate through all of the weapon objects
	{
		if (m_weapons[w] != NULL)
		{
			if (m_player->bb_collision(m_weapons[w])) //if the weapon object collides
			{
				m_player->set_damage(m_player->get_damage() + m_weapons[w]->get_value()); //increase player damage by weapon value
				delete m_weapons[w]; //delete the weapon
				m_weapons[w] = NULL;
				break;
			}
		}
	}
}

void Level::Perform_NPC_Encounter()
{
	for (size_t n = 0; n < m_npcs.size(); n++) //iterate through all of the NPC objects
	{
		if (m_npcs[n] != NULL)
		{
			if (m_player->bb_collision(m_npcs[n])) //if there is a collision between an NPC and the player
			{
				m_npcs[n]->set_display_box(true); //make NPC text visible
				m_npcs[n]->Update(); //update the NPC text box
				m_npcs[n]->React(m_player); //have the NPC react to the player
				break;
			}
			else //if there isn't a collision between an NPC and the player
			{
				m_npcs[n]->set_display_box(false); //make the text box invisible
			}
		}
	}
}

void Level::Move_All(int xAmount, int yAmount)
{
	m_current_time = m_timer->Milliseconds_Since_Last_Call() * 10; //time since last call

	float movementX = xAmount * m_current_time; //x movement * time since last call
	float movementY = yAmount * m_current_time; //y movement * time since last call

	if (m_player->Is_Contained(m_areas, { movementX, movementY })) //if player moved by movementX and movementY is within level bounds
	{

		Move(movementX, movementY, m_areas); //move each area element
		Move(movementX, movementY, m_enemies); //move each enemy
		Move(movementX, movementY, m_weapons); //move each weapon
		Move(movementX, movementY, m_npcs); //move each NPC
		Move(movementX, movementY, m_pickables); //move each pickable
		Move(movementX, movementY, m_level_trigger); //move the level trigger
	}

}

//this function is a template so that it can handle different types that inherit from the same base class
//each vector given to this has a base class of AW_Sprite_Interface but are different inherited classes
template<typename T>
void Level::Move(int xAmount, int yAmount, std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++) //iterate through vector
	{
		if (inputVector[i] != NULL) //if vector element exists
		{
			inputVector[i]->Move_By(xAmount, yAmount); //move it by the amount the player needs to move
			if (inputVector[i]->Has_Target()) //if the vector element has a target
			{
				inputVector[i]->Move_Toward(); //move the element toward the target
				inputVector[i]->Increment_Target(); //check if the current target needs to be incremented
				inputVector[i]->Update_Target_Position(xAmount, yAmount); //update all target positions with new level positions
			}
		}
	}
}

//this function is the same as the above but takes a single element instead of a vector
template <typename T>
void Level::Move(int xAmount, int yAmount, T* sprite)
{
	if (sprite != NULL)
	{
		sprite->Move_By(xAmount, yAmount);
		if (sprite->Has_Target())
		{
			sprite->Move_Toward();
			sprite->Increment_Target();
			sprite->Update_Target_Position(xAmount, yAmount);
		}
	}
}


void Level::Render_All()//render all elements of level in reverse order of appearance 
{
	Render(m_areas); 
	Render(m_enemies);
	Render(m_weapons);
	Render(m_npcs);
	Render(m_pickables);
	if (m_level_trigger != NULL) //if level trigger exists
	{
		m_level_trigger->Render(); //as level trigger is a single element we just call it's own render function
	}
}

//this function is a template so that it can handle different types that inherit from the same base class
//each vector given to this has a base class of AW_Sprite_Interface but are different inherited classes
template<typename T>
void Level::Render(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++) //iterate through inputVector
	{
		if (inputVector[i] != NULL) //if vector element exists
		{
			inputVector[i]->Render(); //call vector elements own render function
		}
	}
}

void Level::Reset_All_Positions()
{
	//if the player dies we reset all level element positions
	Reset_Positions(m_areas);
	Reset_Positions(m_enemies);
	Reset_Positions(m_weapons);
	Reset_Positions(m_npcs);
	Reset_Positions(m_pickables);
	if (m_level_trigger != NULL)
	{
		m_level_trigger->Move_To_Spawn();
	}
}

template<typename T>
void Level::Reset_Positions(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++) //iterate through inputVector
	{
		if (inputVector[i] != NULL) //if vector element exists
		{
			inputVector[i]->Move_To_Spawn(); //set vector element position to spawn position which was stored when the element was created
		}
	}
}


AW_Sprite_Interface* Level::get_trigger() //we allow the getting of the level trigger because we use it to determine the next level to load
{
	return m_level_trigger;
}