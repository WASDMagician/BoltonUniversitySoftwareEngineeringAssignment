#include "Splash_Screen.h"

#include "Game.h"

Splash_Screen::Splash_Screen()
{
}

Splash_Screen::Splash_Screen(Game* pGame, char* bgImg)
:m_b_close_splash(false), m_b_game_over(false)
{
	m_p_game = pGame;
	m_p_game->SetBackground(bgImg);
}

Splash_Screen::~Splash_Screen()
{
	delete m_p_game;
}


void Splash_Screen::Process_Keys()
{
	switch (m_p_game->keyDown)
	{
	case (SDLK_RETURN) :
		m_b_close_splash = true;
		break;
	case(SDLK_ESCAPE) :
		m_b_close_splash = true;
		m_b_game_over = true;
		break;
	}
}

void Splash_Screen::Handle_Start_Keys()
{

}

void Splash_Screen::Handle_Pause_Keys()
{

}

void Splash_Screen::Handle_End_Keys()
{

}

void Splash_Screen::Start()
{
	while (!m_b_close_splash)
	{
		SDL_Delay(10);
		m_p_game->GetUserInput();
		Process_Keys();
		SDL_BlitSurface(m_p_game->bg, NULL, m_p_game->screen, NULL);
		SDL_Flip(m_p_game->screen);
	}
}

bool Splash_Screen::Run()
{
	return true;
}

bool Splash_Screen::is_game_over()
{
	return m_b_game_over;
}



