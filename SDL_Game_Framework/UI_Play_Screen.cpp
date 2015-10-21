#include "UI_Play_Screen.h"


UI_Play_Screen::UI_Play_Screen()
:m_collectibles(0), m_health(100), m_ammunition(0), m_lives(5), m_score(0), m_name("Pleb")
{

}

UI_Play_Screen::UI_Play_Screen(unsigned int items, unsigned int health, unsigned int ammo, unsigned int lives, unsigned int score, std::string name)
: m_collectibles(items), m_health(health), m_ammunition(ammo), m_lives(lives), m_score(score), m_name(name)
{
}


UI_Play_Screen::~UI_Play_Screen()
{
}

bool UI_Play_Screen::Flicker(unsigned int numOfFlicks)
{
	for (unsigned int i = 0; i < numOfFlicks; i++)
	{
		get_flicker_sprite()->set_visibility(true);
		get_flicker_sprite()->set_visibility(false);
		//get_flicker_sprite()->set_visibility(!(get_flicker_sprite()->get_visibility()));
	}
	return true;
}

bool UI_Play_Screen:: set_ammunition(unsigned int ammo)
{
	if (ammo == m_ammunition)
	{
		return false;
	}
	else
	{
		m_ammunition = ammo;
		return true;
	}
}

bool UI_Play_Screen:: set_collectibles(unsigned int items)
{
	if (items == m_collectibles)
	{
		return false;
	}
	else
	{
		m_collectibles = items;
		return true;
	}
}

bool UI_Play_Screen:: set_lives(unsigned int lives)
{
	if(lives == m_lives)
	{
		return false;
	}
	else
	{
		m_lives = lives;
		return true;
	}
}

bool UI_Play_Screen:: set_health(unsigned int health)
{
	if (health == m_health)
	{
		return false;
	}
	else
	{
		m_health = health;
		return true;
	}
}

bool UI_Play_Screen:: set_score(unsigned int score)
{
	if (score == m_score)
	{
		return false;
	}
	else
	{
		m_score = score;
		return true;
	}
}

void UI_Play_Screen:: Display()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Ammo: " << m_ammunition << std::endl;
	std::cout << "Collectibles: " << m_collectibles << std::endl;
	std::cout << "Lives: " << m_lives << std::endl;
	std::cout << "Health: " << m_health << std::endl;
	std::cout << "Score: " << m_score << std::endl;
}
