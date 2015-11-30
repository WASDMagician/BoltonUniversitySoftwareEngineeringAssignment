#include "Splash_Screen.h"

#include "Game.h"

Splash_Screen::Splash_Screen()
	:m_close_splash(false), m_game_over(false)
{
}

Splash_Screen::Splash_Screen(Game* game)
	:m_close_splash(false), m_game_over(false)
{
	m_game = game;
}

Splash_Screen::~Splash_Screen()
{
}


void Splash_Screen::Start()
{
	Setup();
	while (!m_close_splash)
	{
		SDL_Flip(m_game->screen);
		SDL_Delay(10);
		m_game->GetUserInput();
		Handle_Keys();
		Logic();
		Render();
	}
}

void Splash_Screen::Setup()
{
}

void Splash_Screen::Logic()
{
}

void Splash_Screen::Handle_Keys()
{
}

void Splash_Screen::Render()
{
	Render_Back();
	Render_Mid();
	Render_Front();
}

void Splash_Screen:: Render_Back()
{
	SDL_BlitSurface(m_game->bg, NULL, m_game->screen, NULL);
}

void Splash_Screen:: Render_Mid()
{
}

void Splash_Screen:: Render_Front()
{
}


bool Splash_Screen::Run()
{
	return m_close_splash;
}

bool Splash_Screen::is_game_over()
{
	return m_game_over;
}



