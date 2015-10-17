#ifndef _UI_H_
#define _UI_H_

#include <string>

class UI
{
public:
	UI();
	UI(float items, float health, unsigned int ammo, unsigned int lives, std::string name);
	~UI();
	bool Display(); // i know Joe likes his bools rather than void
	bool Flicker(); // Don't know how hard this would be but if you take damage flicker the screen would be cool

private:
	float m_collectibles; // number of items obtained currently
	float m_health; // current health
	unsigned int m_ammunition; // assuming we gonna have some kind of projectiles to shoot enemies with
	unsigned int m_lives; // this or health use which everyone else prefers, i'd prefer health so we can have a slow decay of health in lava or whatever than a fixed life. Maybe...
	std::string m_name; // so we can display players name to HUD
	//Timer* timer // maybe add a timer in here or something to add a speedrun element to the game up to you guys
};
#endif