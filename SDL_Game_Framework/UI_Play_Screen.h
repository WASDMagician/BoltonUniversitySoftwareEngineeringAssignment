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

	bool Flicker(unsigned int numOfFlicks); // do we need to add parameters to virtual void Flicker and change to bool???

	bool set_ammunition(unsigned int ammo);
	bool set_collectibles(unsigned int items);
	bool set_lives(unsigned int lives);
	bool set_health(unsigned int health);
	bool set_score(unsigned int score);

	void Display();

	bool m_flickering;
	Game_Object *m_flicker_object;
	

private:
	std::string m_name; // so we can display players name to HUD
	unsigned int m_ammunition; // assuming we gonna have some kind of projectiles to shoot enemies with
	unsigned int m_collectibles; // number of items obtained currently
	int m_lives; // this or health use which everyone else prefers, i'd prefer health so we can have a slow decay of health in lava or whatever than a fixed life. Maybe...
	unsigned int m_health; // current health // An idea for health is have 5 blocks/hearts/character images representing 5 pieces of hp
	unsigned int m_score;

	

	/* Inaccessible
	AWSprite* flickersprite;
	AW_Sprite_Interface* flickersprite;
	*/

	//Timer* timer // maybe add a timer in here or something to add a speedrun element to the game up to you guys
	//AW_Sprite_Interface rect = new AW_Sprite_Interface(width, height, red, green, blue);
};

#endif // End of _UI_PLAY_SCREEN_H_
