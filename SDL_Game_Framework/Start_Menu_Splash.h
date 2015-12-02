#ifndef _Start_Menu_Splash_H_
#define _Start_Menu_Splash_H_

#include "Splash_Screen.h"
class Start_Menu_Splash :
	public Splash_Screen
{
public:
	Start_Menu_Splash(Game *game);
	~Start_Menu_Splash();

	void Setup();

	void Handle_Keys();

	void Render_Back();
	void Render_Mid();

	bool Run();

private:
	Text_Box* m_instruction_box;
};

#endif // _Start_Menu_Splash_H_