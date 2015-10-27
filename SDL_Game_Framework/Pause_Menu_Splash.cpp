#include "Pause_Menu_Splash.h"

Pause_Menu_Splash::Pause_Menu_Splash()
	:Splash_Screen(NULL, NULL, "Pause_Menu_Splash")
{

}

Pause_Menu_Splash::Pause_Menu_Splash(Game *pGame, char* bgImg)
	: Splash_Screen(pGame, bgImg, "Pause_Menu_Splash")
{

}

Pause_Menu_Splash::~Pause_Menu_Splash(void)
{

}

bool Pause_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}