#ifndef _PAUSE_MENU_SPLASH_H_
#define _PAUSE_MENU_SPLASH_H_

#include "Splash_Screen.h"

class Pause_Menu_Splash :
	public Splash_Screen
{
public:
	Pause_Menu_Splash();
	Pause_Menu_Splash(Game *pGame, char* bgImg);
	~Pause_Menu_Splash();

	bool Run();
};
#endif // _PAUSE_MENU_SPLASH_H_
