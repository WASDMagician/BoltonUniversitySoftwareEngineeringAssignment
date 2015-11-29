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

void Enemy::Setup(char* imgPath, int rows, int cols, int animationSpeed)
{
	setImage(imgPath, rows, cols);
}

void Enemy::Update()
{
	Enemy_Movement();
}

void Enemy::Enemy_Movement()
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

void Enemy::Enemy_Idle()
{
}

void Enemy::Enemy_Roam()
{
	Move_Toward();
}

void Enemy::Enemy_Attack()
{

}

void Enemy::Enemy_Dead()
{

}