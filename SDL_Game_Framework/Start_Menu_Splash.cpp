#include "Start_Menu_Splash.h"
#include "Game.h"

Start_Menu_Splash::Start_Menu_Splash()
	:Splash_Screen(NULL, NULL, "Start_Menu_Splash")
{

}

Start_Menu_Splash::Start_Menu_Splash(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg, "Start_Menu_Splash")
{

}

Start_Menu_Splash::~Start_Menu_Splash(void)
{

}

bool Start_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}