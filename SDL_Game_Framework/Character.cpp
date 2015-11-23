#include "Character.h"

Character::Character()
	:AW_Sprite_Interface(), m_health(0), m_damage(0), m_defence(0), m_score(0), m_message(""), m_message_box(NULL)
{

}

Character::Character(char* imgPath, int rows, int cols, int animationSpeed, std::string message)
	: AW_Sprite_Interface(imgPath, rows, cols, animationSpeed), m_health(0), m_damage(0), m_defence(0), m_score(0), m_message(message), m_message_box(NULL)
{
	set_message(message);
}

Character::~Character()
{
}

bool Character::set_score(int score)
{
	m_score = score;
	return m_score == score;
}

int Character::get_score()
{
	return m_score;
}

void Character::set_message(std::string hint)
{
	m_message_box = new Text_Box();
	m_message_box->set_font("fonts/game_font.ttf", 18);
	m_message_box->set_color(255, 255, 255);
	m_message_box->Add_Message(hint);
	m_message_box->Position_Setting(get_x(), get_y(), 0, 0);
	m_message_box->Setup_Box();
	m_message_box->set_rects();
	m_message_box->set_should_display(true);
}

const std::string Character::get_message()
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
	m_message_box->Position_Setting(get_x(), get_y(), 0, 0);
	m_message_box->set_rects();
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