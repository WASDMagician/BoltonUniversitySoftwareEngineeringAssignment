#include "Enemy.h"


Enemy::Enemy()
{
	character = new Character("images/enemy.png", 0, 0, "Enemy"); // Might change this so that we can set specific enemies
}


Enemy::~Enemy()
{
	//Make sure we delete the pointers
	delete character;
	character = NULL;
}

bool Enemy::enemy_movement()
{
	// Simple AI stuff for our game
	switch (enemyState)
	{
	case IDLE:
		enemy_idle();
		break;
	case ROAMING:
		enemy_roam();
		break;
	case ATTACK:
		enemy_attack();
		break;
	case DEAD:
		enemy_dead();
		break;
	}
}

bool Enemy::enemy_idle()
{
	if (enemyState == IDLE)
	{
		return true;
	}

	return false;
}

bool Enemy::enemy_roam()
{
	if (enemyState == ROAMING)
	{
		return true;
	}

	return false;
}

bool Enemy::enemy_attack()
{
	if (enemyState == ATTACK)
	{
		return true;
	}

	return false;
}

bool Enemy::enemy_dead()
{
	if (enemyState == DEAD)
	{
		return true;
	}

	return false;
}

int Enemy::get_enemy_name()
{
	return m_name;
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

