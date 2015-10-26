#ifndef _Start_Menu_Splash_H_
#define _Start_Menu_Splash_H_

#include "Splash_Screen.h"
class Start_Menu_Splash :
	public Splash_Screen
{
public:
	Start_Menu_Splash();
	Start_Menu_Splash(Game *pGame, char* bgImg);
	~Start_Menu_Splash();

	bool Run();

private:

};

#endif // _Start_Menu_Splash_H_