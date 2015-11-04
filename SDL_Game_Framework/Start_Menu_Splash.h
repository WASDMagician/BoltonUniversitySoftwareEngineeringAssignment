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

	void Setup();

	void Logic();

	void Handle_Keys();

	void Render_Back();
	void Render_Mid();
	void Render_Front();

	bool Run();

private:
	Text_Box tb;
};

#endif // _Start_Menu_Splash_H_