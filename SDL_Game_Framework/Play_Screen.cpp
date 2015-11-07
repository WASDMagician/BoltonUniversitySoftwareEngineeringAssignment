#include "Play_Screen.h"
#include "Level_One.h"
#include "Game.h"

Play_Screen::Play_Screen()
	:Splash_Screen(NULL, NULL, "Play_Screen")
{

}

Play_Screen::Play_Screen(Game *pGame, char* bgImg)
	: Splash_Screen(pGame, bgImg, "Play_Screen")
{
	m_p_game->SetBackground(bgImg);
	m_unpaused_image_path = bgImg;
	m_paused_image_path = "images/pause_menu_splash_temp.png";
}

Play_Screen::~Play_Screen(void)
{

}

void Play_Screen::Setup()
{
	m_b_paused = false;
	char_factory = new Character_Factory_Implementation();
	m_player = char_factory->Make_Character(PLAYER);
	m_player->set_world_position(400, 300);
	m_level = new Level_One();
}

void Play_Screen::Logic()
{

}

void Play_Screen::Handle_Keys()
{
	switch (m_p_game->keyDown)
	{
	case(SDLK_SPACE) :
		printf("Play");
		break;
	case(SDLK_RETURN) :
		printf("Switch");
		m_b_close_splash = true;
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

	switch (m_p_game->keyUp)
	{
	case(SDLK_p) :
		printf("Paused: %d\n", m_b_paused);
		break;
	default:
		break;
	}
}

void Play_Screen::Move(int xAmount, int yAmount)
{
	m_level->Move(xAmount, yAmount);
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

void Play_Screen::Toggle_Pause()
{
	m_b_paused = !m_b_paused;
	if (m_b_paused)
	{
		m_p_game->SetBackground(m_paused_image_path);
	}
	else
	{
		m_p_game->SetBackground(m_unpaused_image_path);
	}
	
}