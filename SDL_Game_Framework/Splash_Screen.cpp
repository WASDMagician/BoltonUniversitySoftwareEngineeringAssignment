#include "Splash_Screen.h"

#include "Game.h"

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
	Setup(); //blank function call to be overridden by inheriting classes
	while (!m_close_splash && !m_game_over) //if the splash screen should be closed or the game should be ended
	{
		SDL_Flip(m_game->screen); //flip screen
		m_game->GetUserInput(); //get input from player 
		Handle_Keys(); //blank function call to be overriden by inheriting classes, deals with input from previous step
		Logic(); //blank function call to be overriden by inheriting classes, handles the logic of each screen
		Render(); //each inheriting class uses Render in the same way so it makes sense to have it here
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
	//render functions called in display order, front infront of mid, mid infront of background, background at back
	Render_Back(); //blank function call to be overriden by inheriting classes
	Render_Mid(); //blank function call to be overriden by inheriting classes
	Render_Front(); //blank function call to be overriden by inheriting classes
}

void Splash_Screen:: Render_Back()
{
}

void Splash_Screen:: Render_Mid()
{
}

void Splash_Screen:: Render_Front()
{
}

bool Splash_Screen::is_game_over()
{
	return m_game_over; //this is used by all inheriting classes in the same way so declared here
}