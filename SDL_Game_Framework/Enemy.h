#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

enum ENEMY_STATE
{
	IDLE,
	ROAMING,
	ATTACK,
	DEAD
};

class Enemy : public Character
{
public:
	Enemy();
	Enemy(char* img, int rows, int cols, Transform initial_transform, std::string name, 
		unsigned int health, unsigned int damage, unsigned int defence);
	~Enemy();

	bool Enemy_Movement();
	bool Enemy_Idle();
	bool Enemy_Roam();
	bool Enemy_Attack();
	bool Enemy_Dead();
private:
	ENEMY_STATE enemy_state;
};

#endif