#ifndef _PLAY_SPLASH_H_
#define _PLAY_SPLASH_H_

#include "Character_Factory_Implementation.h"
#include "Player.h"
#include "Level.h"
#include "UI_Play_Screen.h"
#include "Splash_Screen.h"
class Play_Screen :
	public Splash_Screen
{
public:
	Play_Screen(Game *game);
	~Play_Screen();

	void Setup();
	void Init_Player();

	void Logic();
	void Handle_Keys();

	bool Check_Level_Collision();

	bool Run();


private:
	void Render_Back();
	void Render_Mid();
	void Render_Front();

	float m_x_amount;
	float m_y_amount;

	Level *m_level;
	Character_Factory_Implementation* m_char_factory;
	Character *m_player;
	UI_Play_Screen *m_screen_ui;
};

#endif // _PLAY_SPLASH_H_