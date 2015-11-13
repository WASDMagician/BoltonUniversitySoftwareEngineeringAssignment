#ifndef _PLAY_SPLASH_H_
#define _PLAY_SPLASH_H_

#include "Character_Factory_Implementation.h"
#include "Player.h"
#include "Level.h"

#include "Splash_Screen.h"
class Play_Screen :
	public Splash_Screen
{
public:
	Play_Screen();
	Play_Screen(Game *pGame, char* bgImg);
	~Play_Screen();

	void Setup();
	void Logic();
	void Handle_Keys();

	void Move(int xAmount, int yAmount);
	bool Check_Level_Trigger();
	bool Check_Enemy_Trigger();
	bool Check_Coin_Trigger();
	bool Check_Weapon_Trigger();

	void Render();
	void Render_Back();
	void Render_Mid();
	void Render_Front();

	bool Run();


private:
	
	Level *m_level;
	Character_Factory_Implementation* char_factory;
	Character *m_player;

	bool m_b_paused;

	bool m_b_has_attacked;
};

#endif // _PLAY_SPLASH_H_