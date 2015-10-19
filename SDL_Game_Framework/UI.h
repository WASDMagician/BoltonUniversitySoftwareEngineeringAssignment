#ifndef _UI_H_
#define _UI_H_

#include <string>
#include <iostream>

class UI
{
public:
	UI();
	UI(float items, float health, unsigned int ammo, int lives, unsigned int score, std::string name);
	~UI();
	bool Display(); // i know Joe likes his bools rather than void
	bool Flicker(); // Don't know how hard this would be but if you take damage flicker the screen would be cool
	
	bool Update_Score();
	bool Update_Lives();
	bool Update_Inventory();
	bool Update_Health();
	bool Update_Ammo();

private:
	float m_collectibles; // number of items obtained currently
	float m_health; // current health
	unsigned int m_ammunition; // assuming we gonna have some kind of projectiles to shoot enemies with
	int m_lives; // this or health use which everyone else prefers, i'd prefer health so we can have a slow decay of health in lava or whatever than a fixed life. Maybe...
	unsigned int m_score;
	std::string m_name; // so we can display players name to HUD
	unsigned int m_score_modifier = 50;
	bool m_ui_success = false;
	bool m_score_increment = false;
	//Timer* timer // maybe add a timer in here or something to add a speedrun element to the game up to you guys

	unsigned int Get_Score() const{ return m_score; }
};
#endif