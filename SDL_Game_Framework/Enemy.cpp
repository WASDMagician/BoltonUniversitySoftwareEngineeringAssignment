#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(char* imgPath, int rows, int cols, int animationSpeed)
	:Character(imgPath, rows, cols, animationSpeed)
{
}

Enemy::~Enemy()
{

}

bool Enemy::Setup(char* imgPath, int rows, int cols, int animationSpeed)
{
	setImage(imgPath, rows, cols);
	return false;
}

void Enemy::Update()
{

}

void Enemy::Render()
{
	update_everything();
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
		//Stop and dont do anything
		enemy_state = ROAMING; //we need to have some timer stuff going on here
		return true;
	}

	return false;
}

bool Enemy::Enemy_Roam()
{
	if (enemy_state == ROAMING)
	{
		Move_Between();
		return true;
	}

	return false;
}

bool Enemy::Enemy_Attack()
{
	if (enemy_state == ATTACK)
	{
		//if player is in sight, attack it
		return true;
	}

	return false;
}

bool Enemy::Enemy_Dead()
{
	if (enemy_state == DEAD)
	{
		//handle some enemy death stuff here
		return true;
	}

	return false;
}

bool Enemy::set_name(std::string name)
{
	m_name = name;
	return m_name == name;
}

std::string Enemy::get_name()
{
	return m_name;
}

bool Enemy::set_health(unsigned int health)
{
	m_health = health;
	return m_health == health;
}

bool Enemy::set_lives(unsigned int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

unsigned int Enemy::get_lives()
{
	return m_lives;
}

unsigned int Enemy::get_health()
{
	return m_health;
}

bool Enemy::set_damage(unsigned int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

unsigned int Enemy::get_damage()
{
	return m_damage;
}

bool Enemy::set_defence(unsigned int defence)
{
	m_defence = defence;
	return m_defence == defence;
}

unsigned int Enemy::get_defence()
{
	return m_defence;
}

bool Enemy::Attack(Character* target)
{
	return false;
}

bool Enemy::Defend(Character* target)
{
	return false;
}