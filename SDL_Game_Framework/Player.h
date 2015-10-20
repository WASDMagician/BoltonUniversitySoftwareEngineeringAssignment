#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class UI_Play_Screen;

class Player : public Character
{
public:
	Player();
	Player(char* img, int rows, int cols, std::string name, 
			unsigned int health, unsigned int defence, unsigned int damage, unsigned int lives);
	~Player();

	unsigned int get_lives();
	void set_lives(unsigned int lives);

	void update_player_ui();

private:
	unsigned int m_lives;
	UI_Play_Screen *player_ui;
};

#endif

