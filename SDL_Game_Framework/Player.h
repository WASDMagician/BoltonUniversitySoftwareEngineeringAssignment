#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(char* img, int rows, int cols, SDL_Colour colour, Transform trans, std::string name, 
			unsigned int health, unsigned int defence, unsigned int damage);
	~Player();

private:

};

#endif

