#include "Play_Screen.h"
#include "Level_One.h"
#include "Level_Two.h"
#include "Level_Three.h"
#include "Game.h"

Play_Screen::Play_Screen()
	:Splash_Screen(NULL, NULL, "Play_Screen"), m_play_time(NULL), m_level(NULL), char_factory(NULL), m_player(NULL),
	screen_ui(NULL), m_last_encounter(0), m_encounter_gap(2)
{

}

Play_Screen::Play_Screen(Game *pGame, char* bgImg)
	: Splash_Screen(pGame, bgImg, "Play_Screen"), m_play_time(NULL), m_level(NULL), char_factory(NULL), m_player(NULL),
	screen_ui(NULL), m_last_encounter(0), m_encounter_gap(2)
{
	m_p_game->SetBackground(bgImg);
}

Play_Screen::~Play_Screen(void)
{

}

void Play_Screen::Setup()
{
	m_play_time = std::clock();
	char_factory = new Character_Factory_Implementation();
	Init_Player();
	screen_ui = new UI_Play_Screen();
	screen_ui->set_character(m_player);

	m_level = new Level_One("one");
}

void Play_Screen::Init_Player()
{
	m_player = char_factory->Make_Character(PLAYER);
	m_player->set_name("Dave");
	m_player->set_health(100);
	m_player->set_lives(3);
	m_player->set_score(0);
	m_player->set_damage(20);
	m_player->Move_To(400, 300);

}

void Play_Screen::Logic()
{
	m_play_time = clock();
	if (Check_Level_Trigger())
	{
		if (m_level->get_level_name() == "one")
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Two("two");
		}
		else if (m_level->get_level_name() == "two")
		{
			delete m_level;
			m_level = NULL;
			m_level = new Level_Three("three");
		}
		else if (m_level->get_level_name() == "three")
		{
			m_b_close_splash = true;
		}
	}
	
	Perform_Enemy_Encounter();
	
	Check_Coin_Trigger();
	Check_Weapon_Trigger();
	Check_NPC_Trigger();
	
	screen_ui->Update();
	
	for (auto &m : m_level->get_enemies())
	{
		m->Update();
	}
}

void Play_Screen::Handle_Keys()
{
	const Uint8 *state = SDL_GetKeyState(NULL);

	int speed = 5;

	int x_move = 0;
	int y_move = 0;

	if (state[SDLK_LEFT] || state[SDLK_a])
	{
		x_move = speed;
	}
	if (state[SDLK_RIGHT] || state[SDLK_d])
	{
		x_move = -speed;
	}
	if (state[SDLK_UP] || state[SDLK_w])
	{
		y_move = speed;
	}
	if (state[SDLK_DOWN] || state[SDLK_s])
	{
		y_move = -speed;
	}
	
	Move(x_move, y_move);
}

void Play_Screen::Move(int xAmount, int yAmount) //handle all level movement
{
	if (m_player->Is_Contained(m_level->get_areas(), { xAmount, yAmount }))
	{
		for (size_t i = 0; i < m_level->get_areas().size(); i++)
		{
			m_level->Move_All(xAmount, yAmount);
		}
	}
}

bool Play_Screen::Check_Level_Trigger()
{
	return (m_level->get_trigger()->bb_collision(m_player));
}

bool Play_Screen::Perform_Enemy_Encounter()
{
	std::vector<Character*>enemies = m_level->get_enemies();
	for (size_t e = 0; e < enemies.size(); e++)
	{
		if (enemies[e]->bb_collision(m_player))
		{
			if (m_play_time / 1000 > m_last_encounter / 1000 + m_encounter_gap / 1000)
			{
				m_player->Attack(enemies[e]);
				enemies[e]->Attack(m_player);

				if (!enemies[e]->Check_Alive())
				{
					enemies[e]->set_visibility(false);
				}

				if (!m_player->Check_Alive())
				{
					if (m_player->get_lives() > 1)
					{
						m_level->Reset_All_Positions();
						m_player->set_lives(m_player->get_lives() - 1);
					}
					else
					{
						m_b_close_splash = true;
					}
				}

				m_last_encounter = m_play_time;
			}
		}
	}
	return true;
}

bool Play_Screen::Check_NPC_Trigger()
{
	for (auto &npc : m_level->get_npcs())
	{
		if (m_player->bb_collision(npc))
		{
			npc->set_display_box(true);
			npc->Update();
			npc->React(m_player);
			return true;
		}
		else
		{
			npc->set_display_box(false);
		}
	}
	return false;
}

bool Play_Screen::Check_Coin_Trigger()
{
	for (auto &pick_objects : m_level->get_pickables())
	{
		if (m_player->bb_collision(pick_objects))
		{
			m_player->set_score(m_player->get_score() + 1); //@debug
			pick_objects->set_visibility(false);
			return true;
		}
	}
	return false;
}

bool Play_Screen::Check_Weapon_Trigger()
{
	for (auto &weapon : m_level->get_weapons())
	{
		if (m_player->bb_collision(weapon))
		{
			m_player->set_damage(m_player->get_damage() + 10);
			weapon->set_visibility(false);
			return true;
		}
	}
	return false;
}

void Play_Screen::Render()
{
	Render_Back();
	Render_Mid();
	Render_Front();
}

void Play_Screen:: Render_Back()
{

	SDL_FillRect(m_p_game->screen, NULL, 0x000000); //bleh, not sure about this, stops tearing
	m_level->Render_All();
}

void Play_Screen:: Render_Mid()
{
	m_player->update_everything();
}

void Play_Screen:: Render_Front()
{
	screen_ui->Display();
}

bool Play_Screen::Run()
{
	Start();
	return is_game_over();
}

