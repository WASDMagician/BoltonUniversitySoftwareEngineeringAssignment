#include "Enemy.h"

Enemy::Enemy()
:Character()
{
}

Enemy::Enemy(char* imgPath, int rows, int cols, int animationSpeed)
:Character(imgPath, rows, cols, animationSpeed, "")
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
	Enemy_Movement();
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
	Move_Toward();

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

bool Enemy::set_health(int health)
{
	m_health = health;
	return m_health == health;
}

bool Enemy::set_lives(int lives)
{
	m_lives = lives;
	return m_lives == lives;
}

int Enemy::get_lives()
{
	return m_lives;
}

int Enemy::get_health()
{
	return m_health;
}

bool Enemy::set_damage(int damage)
{
	m_damage = damage;
	return m_damage == damage;
}

int Enemy::get_damage()
{
	return m_damage;
}

bool Enemy::set_score(int score)
{
	m_score = score;
	return m_score == score;
}

int Enemy::get_score()
{
	return m_score;
}

bool Enemy::Check_Alive()
{
	return m_health > 0;
}

bool Enemy::React(Character* target)
{
	return false;
}