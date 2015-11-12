#include "Play_Screen.h"
#include "Level_One.h"
#include "Level_Two.h"
#include "Level_Three.h"
#include "Game.h"

Play_Screen::Play_Screen()
	:Splash_Screen(NULL, NULL, "Play_Screen")
{

}

Play_Screen::Play_Screen(Game *pGame, char* bgImg)
	: Splash_Screen(pGame, bgImg, "Play_Screen")
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
	m_level->Move_Enemies();
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
}

void Play_Screen::Handle_Keys()
{
	switch (m_p_game->keyDown)
	{
	case(SDLK_LEFT) :
		Move(10, 0);
		break;
	case(SDLK_RIGHT) :
		Move(-10, 0);
		break;
	case(SDLK_UP) :
		Move(0, 10);
		break;
	case(SDLK_DOWN) :
		Move(0, -10);
		break;
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
