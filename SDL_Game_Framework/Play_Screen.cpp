#include "Play_Screen.h"
#include "Level_One.h"
#include "Level_Two.h"
#include "Level_Three.h"
#include "Game.h"

Play_Screen::Play_Screen()
:Splash_Screen(NULL, NULL, "Play_Screen"), m_b_has_attacked(false)
{

}

Play_Screen::Play_Screen(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg, "Play_Screen"), m_b_has_attacked(false)
{
	m_p_game->SetBackground(bgImg);
}

Play_Screen::~Play_Screen(void)
{

}

void Play_Screen::Setup()
{
	m_b_paused = false;
	char_factory = new Character_Factory_Implementation();
	m_player = char_factory->Make_Character(PLAYER);
	m_player->Move_To(400, 300);
	m_level = new Level_One("one");
}

void Play_Screen::Logic()
{
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
	Check_Enemy_Trigger();
	Check_Coin_Trigger();
	Check_Weapon_Trigger();
	Check_NPC_Trigger();

	for (auto &m : m_level->get_enemies())
	{
		m->Update();
	}
}

void Play_Screen::Handle_Keys()
{
	const Uint8 *state = SDL_GetKeyState(NULL);

	int x_move = 0;
	int y_move = 0;

	if (state[SDLK_LEFT] || state[SDLK_a])
	{
		x_move = 10;
	}
	if (state[SDLK_RIGHT] || state[SDLK_d])
	{
		x_move = -10;
	}
	if (state[SDLK_UP] || state[SDLK_w])
	{
		y_move = 10;
	}
	if (state[SDLK_DOWN] || state[SDLK_s])
	{
		y_move = -10;
	}
	
	Move(x_move, y_move);
	for (size_t i = 0; i < m_level->get_enemies().size(); i++)
	{
		//printf("Angle: %d Distance: %d\n", m_player->get_angle_between(m_level->get_enemies()[i]), m_player->get_distance_between(m_level->get_enemies()[i])); //@debug
	}
	
}

void Play_Screen::Move(int xAmount, int yAmount)
{
	m_level->Move(xAmount, yAmount);
}

bool Play_Screen::Check_Level_Trigger()
{
	return (m_level->get_trigger()->bb_collision(m_player));
}

bool Play_Screen::Check_Enemy_Trigger()
{
	for (auto &enemy : m_level->get_enemies())
	{
		if (enemy != NULL)
		{
			if (enemy->bb_collision(m_player))
			{
				if (!m_b_has_attacked)
				{
					m_b_has_attacked = false; //should be true
					m_player->Attack(enemy);
					enemy->Attack(m_player);
					 // DISPLAY REDUCTION IN LIVES IF U GET REKT IN HERE 
					printf("Player: %d %u %u\n", m_player->get_health(), m_player->get_damage(), m_player->get_defence()); //@debug
					printf("Enemy: %d, %u, %u\n", enemy->get_health(), enemy->get_damage(), enemy->get_health()); //@debug

					if (!enemy->Check_Health())
					{
						enemy->set_visibility(false);
					}

					if (!m_player->Check_Health())
					{
						m_b_close_splash = true;
					}
				}
			}
			else
			{
				m_b_has_attacked = false;
			}
		}
		
	}
	return true;
}

bool Play_Screen::Check_NPC_Trigger()
{
	for (auto &n : m_level->get_npcs())
	{
		if (m_player->bb_collision(n))
		{
			n->set_display_box(true);
			n->Update();
			n->react();
			return true;
		}
		else
		{
			n->set_display_box(false);
		}
	}
	return false;
}

bool Play_Screen::Check_Coin_Trigger()
{
	for (auto &c : m_level->get_pickables())
	{
		if (m_player->bb_collision(c))
		{
			m_player->set_score(m_player->get_score() + 1); //@debug
			printf("Player Score: %d\n", m_player->get_score()); //@debug
			c->set_visibility(false);
			return true;
		}
	}
	return false;
}

bool Play_Screen::Check_Weapon_Trigger()
{
	for (auto &w : m_level->get_weapons())
	{
		if (m_player->bb_collision(w))
		{
			m_player->set_score(m_player->get_score() + 1);
			m_player->set_damage(m_player->get_damage() + 10);
			printf("Player Score: %d\n", m_player->get_score()); //@debug
			printf("Player Damage: %d\n", m_player->get_damage()); //@debug
			w->set_visibility(false);
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
	m_level->Render();
}

void Play_Screen:: Render_Mid()
{
	m_player->update_everything();
}

void Play_Screen:: Render_Front()
{
}

bool Play_Screen::Run()
{
	Start();
	return is_game_over();
}

