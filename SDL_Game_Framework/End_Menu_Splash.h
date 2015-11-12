#ifndef _END_MENU_SPLASH_H_
#define _END_MENU_SPLASH_H_

#include "Splash_Screen.h"
class End_Menu_Splash :
	public Splash_Screen
{
public:
	End_Menu_Splash();
	End_Menu_Splash(Game *pGame, char* bgImg);
	~End_Menu_Splash();

	void Setup();

	void Logic();

	void Handle_Keys();

	void Render_Back();
	void Render_Mid();
	void Render_Front();

	bool Run();

private:
	Text_Box* gameover_box;
};

#endif // _End_Menu_Splash_H_