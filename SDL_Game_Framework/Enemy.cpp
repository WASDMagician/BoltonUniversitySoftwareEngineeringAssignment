#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(char* img, int rows, int cols, Transform trans, std::string name, unsigned int health, unsigned int damage, unsigned int defence)
:Character(img, 0, 0, trans, name), m_health(health), m_damage(damage), m_defence(defence)
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

int Enemy::get_health()
{
	return m_health;
}

int Enemy::get_defence()
{
	return m_defence;
}

int Enemy::get_damage()
{
	return m_damage;
}

