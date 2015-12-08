#include "Character.h"

Character::Character()
	:AW_Sprite_Interface(), m_health(0), m_damage(0), m_score(0), m_message(""), m_message_box(NULL)
{

}

Character::Character(char* imgPath, int rows, int cols, std::string message)
	: AW_Sprite_Interface(imgPath, rows, cols), m_health(0), m_damage(0), m_score(0), m_message(message), 
	m_message_box(NULL)
{
	set_message(message);
}

Character::~Character()
{
}

void Character::Setup(char* imgPath, int rows, int cols)
{
	setImage(imgPath, rows, cols);
}

void Character::set_variables(int health, int damage)
{
	m_health = health;
	m_damage = damage;
}

void Character::set_health(int health)
{
	m_health = health;
}

void Character::set_lives(int lives)
{
	m_lives = lives;
}

int Character::get_lives()
{
	return m_lives;
}

int Character::get_health()
{
	return m_health;
}

void Character::set_damage(int damage)
{
	m_damage = damage;
}

int Character::get_damage()
{
	return m_damage;
}

void Character::set_score(int score)
{
	m_score = score;
}

int Character::get_score()
{
	return m_score;
}

bool Character::Check_Alive()
{
	return m_health > 0;
}

void Character::React(Character* target)
{
}

void Character::set_message(std::string hint)
{
	m_message_box = new Text_Box();
	m_message_box->set_font("fonts/game_font.ttf", 18);
	m_message_box->set_color(255, 255, 255);
	m_message_box->Add_Message(hint);
	m_message_box->Position_Setting(get_x(), get_y());
	m_message_box->Setup_Box();
	m_message_box->set_rects();
	m_message_box->set_should_display(true);
}



std::string Character::get_message()
{
	return m_message;
}

void Character::set_display_box(bool display)
{
	m_message_box->set_should_display(display);
}

bool Character::get_display_box()
{
	return m_message_box->get_should_display();
}

void Character::Update()
{
	m_message_box->Position_Setting(get_x(), get_y());
	m_message_box->set_rects();
}

void Character::Attack(Character* target)
{
	target->set_health(target->get_health() - (m_damage));
}

void Character::Render()
{
	Update();
	update_everything();
	if (m_message_box->get_should_display())
	{
		m_message_box->Display();
	}	
}