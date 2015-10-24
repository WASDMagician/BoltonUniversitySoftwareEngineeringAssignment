#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(character_creation_variables *initializer)
:Character(initializer)
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
		//Stop and dont do anything
		return true;
	}

	return false;
}

bool Enemy::Enemy_Roam()
{
	this->transform->Lerp_To(new Vector2{ 20, 50 }, 100, 1);
	this->transform->Lerp_To(new Vector2{ 100, 50 }, 100, 1);
	this->transform->Lerp_To(new Vector2{ 21, 300 }, 100, 1);
	this->transform->Lerp_To(new Vector2{ 60, 10 }, 100, 1);

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

unsigned int Enemy::get_health()
{
	return m_health;
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

std::string Enemy::serialize_character()
{
	return "False";
}

