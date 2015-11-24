#ifndef _UI_PLAY_SCREEN_H_	
#define _UI_PLAY_SCREEN_H_

#include "UI.h"

class Game_Object;

class UI_Play_Screen :
	public UI
{
public:
	UI_Play_Screen();
	UI_Play_Screen(unsigned int items, unsigned int health, unsigned int ammo, unsigned int lives, unsigned int score, std::string name);
	~UI_Play_Screen();

	bool set_character(Character* character);
	bool Setup();

	bool Flicker(unsigned int numOfFlicks); // do we need to add parameters to virtual void Flicker and change to bool???
	
	bool Update();

	void Display();

	bool m_flickering;
	AW_Sprite_Interface *m_flicker_object;
	

private:
	Character *m_display_character;

	Text_Box *UI_Details;

	std::string m_name; // so we can display players name to HUD
	int m_ammunition; // assuming we gonna have some kind of projectiles to shoot enemies with
	int m_collectibles; // number of items obtained currently
	int m_lives; // this or health use which everyone else prefers, i'd prefer health so we can have a slow decay of health in lava or whatever than a fixed life. Maybe...
	int m_health; // current health // An idea for health is have 5 blocks/hearts/character images representing 5 pieces of hp
	int m_score;

};

#endif // End of _UI_PLAY_SCREEN_H_
