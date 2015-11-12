#include "Character.h"

Character::Character()
:AW_Sprite_Interface(), m_health(0), m_damage(0), m_defence(0), m_score(0)
{
}

Character::Character(char* imgPath, int rows, int cols, int animationSpeed)
: AW_Sprite_Interface(imgPath, rows, cols, animationSpeed), m_health(0), m_damage(0), m_defence(0), m_score(0)
{
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