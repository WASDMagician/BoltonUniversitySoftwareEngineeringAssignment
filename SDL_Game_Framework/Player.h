#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	int get_health(); // Get the players current health
	int get_defence(); // Get the players current defence
	int get_damage(); // Get the players current damage
private:
	Character *character;

	int m_health;
	int m_defence;
	int m_damage;
};

#endif

