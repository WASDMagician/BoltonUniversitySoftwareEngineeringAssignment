#ifndef _End_Menu_Splash_h_
#define _End_Menu_Splash_H_

#include "Splash_Screen.h"

class End_Menu_Splash :
	public Splash_Screen
{
public:
	End_Menu_Splash();
	End_Menu_Splash(Game *pGame, char* bgImg);
	~End_Menu_Splash();

	bool Run(); // runs SplashScreen start function and returns whether or not the game is over

private:

};

#endif // _End_Menu_Splash_H_
