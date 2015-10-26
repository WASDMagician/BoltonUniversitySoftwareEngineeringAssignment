#include "End_Menu_Splash.h"


End_Menu_Splash::End_Menu_Splash()
{
}

End_Menu_Splash::End_Menu_Splash(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg)
{

}

End_Menu_Splash::~End_Menu_Splash()
{
}

bool End_Menu_Splash::Run()
{
	start();
	return is_game_over();
}