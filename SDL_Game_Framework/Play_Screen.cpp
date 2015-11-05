#include "Play_Screen.h"
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

void Play_Screen::Render()
{
	Render_Back();
	Render_Mid();
	Render_Front();
}

void Play_Screen:: Render_Back()
{
	SDL_BlitSurface(m_p_game->bg, NULL, m_p_game->screen, NULL);
}

void Play_Screen:: Render_Mid()
{
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