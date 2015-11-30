#include "Enemy.h"

Enemy::Enemy()
	:Character(), m_health_box(NULL)
{
}

Enemy::Enemy(char* imgPath, int rows, int cols, int animationSpeed)
	: Character(imgPath, rows, cols, animationSpeed, ""), m_health_box(NULL)
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
	set_health_message();
}

void Enemy::set_health_message()
{
	m_health_box = new Text_Box();
	m_health_box->set_font("fonts/game_font.ttf", 18);
	m_health_box->set_color(255, 0, 0);
	m_health_box->Add_Message(std::to_string(get_health()));
	m_health_box->Position_Setting(get_x(), get_y() - 20, 0, 0);
	m_health_box->Setup_Box();
	m_health_box->set_rects();
	m_health_box->set_should_display(true);
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

void Enemy::Render()
{
	Character::Render();
	Update();
	if (m_health > 0)
	{
		m_health_box->Display();
	}
}