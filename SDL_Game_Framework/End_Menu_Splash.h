#ifndef _END_MENU_SPLASH_H_
#define _END_MENU_SPLASH_H_

#include "Splash_Screen.h"
class End_Menu_Splash :
	public Splash_Screen
{
public:
	End_Menu_Splash();
	End_Menu_Splash(Game *game);
	~End_Menu_Splash();

	void Setup();
	void Handle_Keys();
	bool Run();

private:
	void Render_Back();
	void Render_Mid();
	Text_Box* m_gameover_box;
};

#endif // _End_Menu_Splash_H_