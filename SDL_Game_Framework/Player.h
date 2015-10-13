#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(char* img, int x, int y, std::string name, unsigned int health, unsigned int defence, unsigned int damage);
	~Player();

	int get_health(); // Get the players current health
	int get_defence(); // Get the players current defence
	int get_damage(); // Get the players current damage
private:

	int m_health;
	int m_defence;
	int m_damage;
};

#endif

