#include "Play_Screen.h"
#include "Level_One.h"
#include "Level_Two.h"
#include "Level_Three.h"
#include "Game.h"

Play_Screen::Play_Screen(Game *pGame)
	: Splash_Screen(pGame), m_level(NULL), m_char_factory(NULL), m_player(NULL),
	m_screen_ui(NULL)
{
}

Play_Screen::~Play_Screen(void)
{
	//free memory
	delete m_level;
	m_level = NULL;
	delete m_char_factory;
	m_char_factory = NULL;

	delete m_player;
	m_player = NULL;
	delete m_screen_ui;
	m_screen_ui = NULL;

}

void Play_Screen::Setup()
{
	m_char_factory = new Character_Factory_Implementation(); //instantiate character factory
	Init_Player(); //create player
	m_screen_ui = new UI_Play_Screen(); //instatiate UI
	m_screen_ui->set_character(m_player); //set character for UI to display

	m_level = new Level_One(m_player); //load in the first level
}

void Play_Screen::Init_Player()
{
	//the player remains the same over multiple levels so is defined here and the levels loaded in separately
	m_player = m_char_factory->Make_Character(PLAYER); //use character factory to create player
	m_player->set_health(100); //set health
	m_player->set_lives(3); //set lives
	m_player->set_score(0); //set score to 0
	m_player->set_damage(20); //set damage
	m_player->Move_To(400, 300); //move to starting position
}

void Play_Screen::Handle_Keys()
{
	if (m_game->keyDown == SDLK_ESCAPE) //if statement used to deal with single key press
	{
		m_game_over = true;
	}
	const Uint8 *state = SDL_GetKeyState(NULL); //use keystates to allow for multiple key presses at the same time
	float speed = 50; //speed at which the player moves

	m_xAmount = 0; //reset x move amount
	m_yAmount = 0; //reset y move amount

	//set x move amount and y move amount to be passed to Levels Move function
	if (state[SDLK_a])
	{
		m_xAmount = speed; //left
	}
	if (state[SDLK_d])
	{
		m_xAmount = -speed; //right
	}
	if (state[SDLK_w])
	{
		m_yAmount = speed; //up
	}
	if (state[SDLK_s])
	{
		m_yAmount = -speed; //down
	}
}

void Play_Screen::Logic()
{
	m_close_splash = m_level->Run_Level_Logic(m_xAmount, m_yAmount); //run through the logic of the currently loaded level

	if (Check_Level_Collision()) //check for a collision with the current levels trigger, if one is found:
	{
		if (m_level->get_level_number() == 3) //if the current level number is 3 then close the splash
		{
			m_close_splash = true;
		}
		if (m_level->get_level_number() == 2) //if the current level number is 2 clear out the old level (2) and load in the new one (3)
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Three(m_player); //load level and pass player to it
		}
		else if (m_level->get_level_number() == 1, m_player) //if the current level number is 1 clear out the old level (1) and load in the new one (2)
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Two(m_player); //load level and pass player to it
		}
	}
	m_screen_ui->Update(); //update player UI
}



bool Play_Screen::Check_Level_Collision()
{
	return (m_level->get_trigger()->bb_collision(m_player));
}

void Play_Screen:: Render_Back() //render level pieces
{
	SDL_FillRect(m_game->screen, NULL, 0x000000); //bleh, not sure about this, stops tearing
	m_level->Render_All();
}

void Play_Screen:: Render_Mid() //render player
{
	m_player->update_everything();
}

void Play_Screen:: Render_Front() //render UI ontop of everything else
{
	m_screen_ui->Display();
}

bool Play_Screen::Run()
{
	Start(); //start while loop
	return is_game_over(); //return game_over result of while loop
}

