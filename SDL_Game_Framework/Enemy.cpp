#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(char* img, int rows, int cols, std::string name, 
	unsigned int health, unsigned int damage, unsigned int defence)
:Character(name, health, damage, defence)
{
		
}

Enemy::~Enemy()
{

}

bool Enemy::Enemy_Movement()
{
	// Simple AI stuff for our game
	switch (enemy_state)
	{
	case IDLE:
		Enemy_Idle();
		break;
	case ROAMING:
		Enemy_Roam();
		break;
	case ATTACK:
		Enemy_Attack();
		break;
	case DEAD:
		Enemy_Dead();
		break;
	}
	return true;
}

bool Enemy::Enemy_Idle()
{
	if (enemy_state == IDLE)
	{
		return true;
	}

	return false;
}

bool Enemy::Enemy_Roam()
{
	if (enemy_state == ROAMING)
	{
		return true;
	}

	return false;
}

bool Enemy::Enemy_Attack()
{
	if (enemy_state == ATTACK)
	{
		return true;
	}

	return false;
}

bool Enemy::Enemy_Dead()
{
	if (enemy_state == DEAD)
	{
		return true;
	}

	return false;
}

