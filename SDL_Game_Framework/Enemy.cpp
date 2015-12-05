#include "Enemy.h"

Enemy::Enemy()
	:Character(), m_health_box(NULL)
{
}

Enemy::Enemy(char* imgPath, int rows, int cols)
	: Character(imgPath, rows, cols, ""), m_health_box(NULL)
{
}

Enemy::~Enemy()
{

}

void Enemy::Setup(char* imgPath, int rows, int cols)
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
	delete m_health_box;
	m_health_box = NULL;
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