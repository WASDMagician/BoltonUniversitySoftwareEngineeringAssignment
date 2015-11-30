#include "Play_Screen.h"
#include "Level_One.h"
#include "Level_Two.h"
#include "Level_Three.h"
#include "Game.h"

Play_Screen::Play_Screen()
	:Splash_Screen(NULL), m_level(NULL), m_char_factory(NULL), m_player(NULL),
	m_screen_ui(NULL)
{

}

Play_Screen::Play_Screen(Game *pGame)
	: Splash_Screen(pGame), m_level(NULL), m_char_factory(NULL), m_player(NULL),
	m_screen_ui(NULL)
{
}

Play_Screen::~Play_Screen(void)
{

}

void Play_Screen::Setup()
{
	m_char_factory = new Character_Factory_Implementation();
	Init_Player();
	m_screen_ui = new UI_Play_Screen();
	m_screen_ui->set_character(m_player);

	m_level = new Level_One("one", m_player);
}

void Play_Screen::Init_Player()
{
	m_player = m_char_factory->Make_Character(PLAYER);
	m_player->set_health(100);
	m_player->set_lives(3);
	m_player->set_score(0);
	m_player->set_damage(20);
	m_player->Move_To(400, 300);
}

void Play_Screen::Handle_Keys()
{
	const Uint8 *state = SDL_GetKeyState(NULL);
	float speed = 25;

	m_xAmount = 0;
	m_yAmount = 0;

	if (state[SDLK_LEFT] || state[SDLK_a])
	{
		m_xAmount = speed;
	}
	if (state[SDLK_RIGHT] || state[SDLK_d])
	{
		m_xAmount = -speed;
	}
	if (state[SDLK_UP] || state[SDLK_w])
	{
		m_yAmount = speed;
	}
	if (state[SDLK_DOWN] || state[SDLK_s])
	{
		m_yAmount = -speed;
	}
}

void Play_Screen::Logic()
{
	m_close_splash = m_level->Run_Level_Logic(m_xAmount, m_yAmount);

	if (Check_Level_Collision())
	{
		if (m_level->get_level_name() == "one", m_player)
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Two("two", m_player);
		}
		else if (m_level->get_level_name() == "two")
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Three("three", m_player);
		}
		else if (m_level->get_level_name() == "three")
		{
			m_close_splash = true;
		}
	}

	m_screen_ui->Update();
}



bool Play_Screen::Check_Level_Collision()
{
	return (m_level->get_trigger()->bb_collision(m_player));
}

void Play_Screen:: Render_Back()
{

	SDL_FillRect(m_game->screen, NULL, 0x000000); //bleh, not sure about this, stops tearing
	m_level->Render_All();
}

void Play_Screen:: Render_Mid()
{
	m_player->update_everything();
}

void Play_Screen:: Render_Front()
{
	m_screen_ui->Display();
}

bool Play_Screen::Run()
{
	Start();
	return is_game_over();
}

