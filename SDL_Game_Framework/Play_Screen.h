#ifndef _PLAY_SPLASH_H_
#define _PLAY_SPLASH_H_

#include "Character_Factory_Implementation.h"
#include "Player.h"
#include "Level.h"
#include "UI_Play_Screen.h"
#include "Splash_Screen.h"
#include "Game_Time.h"
class Play_Screen :
	public Splash_Screen
{
public:
	Play_Screen();
	Play_Screen(Game *game);
	~Play_Screen();

	void Setup();
	void Init_Player();

	void Logic();
	void Handle_Keys();

	void Move(int xAmount, int yAmount);
	bool Check_Level_Collision();
	void Perform_Enemy_Encounter();
	void Perform_Coin_Collision();
	void Perform_Weapon_Collision();
	void Perform_NPC_Encounter();

	bool Run();


private:
	void Render_Back();
	void Render_Mid();
	void Render_Front();

	//@update_uml
	Game_Time *m_timer;
	double m_current_time;
	double m_play_time;
	double m_encounter_gap;
	double m_last_encounter;

	Level *m_level;
	Character_Factory_Implementation* m_char_factory;
	Character *m_player;
	UI_Play_Screen *m_screen_ui;
};

#endif // _PLAY_SPLASH_H_