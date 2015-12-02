#include "Level.h"


Level::Level()
	:m_char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), m_level_trigger(NULL), m_player(NULL),
	m_timer(new Game_Time()), m_current_time(0), m_play_time(0), m_encounter_gap(2), m_last_encounter(0), m_level_number(-1)
{
	m_char_fac = new Character_Factory_Implementation();
	m_pickup_fac = new Pick_Objects_Factory_Implementation();
	m_weapon_fac = new Weapon_Factory_Implementation();
}

Level::Level(Character *player)
	: m_char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), m_level_trigger(NULL), m_player(player),
	m_timer(new Game_Time()), m_current_time(0), m_play_time(0), m_encounter_gap(2), m_last_encounter(0), m_level_number(-1)
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

int Level::get_level_number()
{
	return m_level_number;
}

bool Level::Run_Level_Logic(float xAmount, float yAmount)
{
	bool should_close = false;
	m_play_time = m_timer->Seconds_Since_Start();

	Move_All(xAmount, yAmount);

	should_close = Perform_Enemy_Encounter();
	Perform_Coin_Collision();
	Perform_Weapon_Collision();
	Perform_NPC_Encounter();

	if (m_pickables.size() == 0)
	{
		m_level_trigger->set_visibility(true);
	}

	return should_close;
}

bool Level::Perform_Enemy_Encounter()
{
	for (size_t e = 0; e < m_enemies.size(); e++)
	{
		if (m_enemies[e] != NULL)
		{
			m_enemies[e]->Update();
			if (m_enemies[e]->bb_collision(m_player))
			{
				if (m_play_time > m_last_encounter + m_encounter_gap)
				{
					m_player->Attack(m_enemies[e]);
					m_enemies[e]->Attack(m_player);

					if (!m_enemies[e]->Check_Alive())
					{
						delete m_enemies[e];
						m_enemies[e] = NULL;
					}

					if (!m_player->Check_Alive())
					{
						if (m_player->get_lives() > 1)
						{
							Reset_All_Positions();
							m_player->set_lives(m_player->get_lives() - 1);
						}
						else
						{
							return true;
						}
					}

					m_last_encounter = m_play_time;
				}
			}
		}
	}
	return false;
}

void Level::Perform_Coin_Collision()
{
	for (size_t p = 0; p < m_pickables.size(); p++)
	{
		if (m_pickables[p] != NULL && m_player->bb_collision(m_pickables[p]))
		{
			m_player->set_score(m_player->get_score() + m_pickables[p]->get_value());
			delete m_pickables[p];
			m_pickables[p] = NULL;
			m_pickables.erase(m_pickables.begin() + p);
			break;
		}
	}
}

void Level::Perform_Weapon_Collision()
{
	for (auto &weapon : m_weapons)
	{
		if (m_player->bb_collision(weapon))
		{
			m_player->set_damage(m_player->get_damage() + weapon->get_value());
			weapon->set_visibility(false);
			break;
		}
	}
}

void Level::Perform_NPC_Encounter()
{
	for (auto &npc : m_npcs)
	{
		if (m_player->bb_collision(npc))
		{
			npc->set_display_box(true);
			npc->Update();
			npc->React(m_player);
			break;
		}
		else
		{
			npc->set_display_box(false);
		}
	}
}

void Level::Move_All(int xAmount, int yAmount)
{
	m_current_time = m_timer->Milliseconds_Since_Last_Call() * 10;

	float movementX = xAmount * m_current_time;
	float movementY = yAmount * m_current_time;

	if (m_player->Is_Contained(m_areas, { movementX, movementY }))
	{

		Move(movementX, movementY, m_areas);
		Move(movementX, movementY, m_enemies);
		Move(movementX, movementY, m_weapons);
		Move(movementX, movementY, m_npcs);
		Move(movementX, movementY, m_pickables);
		//m_level_trigger->Move(x, y);
		Move(movementX, movementY, m_level_trigger);
	}

}

template<typename T>
void Level::Move(int xAmount, int yAmount, std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		if (inputVector[i] != NULL)
		{
			inputVector[i]->Move_By(xAmount, yAmount);
			if (inputVector[i]->Has_Target())
			{
				inputVector[i]->Move_Toward();
				inputVector[i]->Increment_Target();
				inputVector[i]->Update_Target_Position(xAmount, yAmount);
			}
		}
	}
}

void Level::Move(int xAmount, int yAmount, AW_Sprite_Interface* sprite)
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

void Level::Render_All()
{
	Render(m_areas);
	Render(m_enemies);
	Render(m_weapons);
	Render(m_npcs);
	Render(m_pickables);
	m_level_trigger->Render();
}

template<typename T>
void Level::Render(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		if (inputVector[i] != NULL)
		{
			inputVector[i]->Render();
		}
	}

	m_level_trigger->Render();
}

void Level::Reset_All_Positions()
{
	Reset_Positions(m_areas);
	Reset_Positions(m_enemies);
	Reset_Positions(m_weapons);
	Reset_Positions(m_npcs);
	Reset_Positions(m_pickables);
	m_level_trigger->Move_To_Spawn();
}

template<typename T>
void Level::Reset_Positions(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		if (inputVector[i] != NULL)
		{
			inputVector[i]->Move_To_Spawn();
		}
	}

	m_level_trigger->Move_To_Spawn();
}


AW_Sprite_Interface* Level::get_trigger()
{
	return m_level_trigger;
}

std::vector<Character*> Level::get_enemies()
{
	return m_enemies;
}

std::vector<Character*> Level::get_npcs()
{
	return m_npcs;
}

std::vector<Pickup_Objects*> Level::get_pickables()
{
	return m_pickables;
}

std::vector<Weapon*> Level::get_weapons()
{
	return m_weapons;
}