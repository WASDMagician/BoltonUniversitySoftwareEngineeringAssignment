#include "UI.h"

UI::UI() //default constructor
{
	m_collectibles = 0;
	m_health = 100;
	m_ammunition = 15;
	m_lives = 5;
	m_score = 0;
	m_name = "Pleb";
}

UI::UI(float items, float health, unsigned int ammo, int lives,unsigned int score, std::string name) // 4 parameter constructor
{
	m_collectibles = items;
	m_health = health;
	m_ammunition = ammo;
	m_lives = lives;
	m_score = score;
	m_name = name;
}

UI::~UI()
{
	//Appropriate memory clean up here
}

bool UI::Update_Score()
{
	if (m_score < 0)
	{
		m_score = 0;
	}
	if (m_score_increment == false)
	{
		m_score = m_score += m_score_modifier;
		std::cout << "Score: " << m_score << std::endl;
		if (m_score == 1000)
		{
			m_score_increment = true;
		}
		return true;
	}
}

bool UI::Update_Lives()
{
	if (m_lives > 0)
	{
		std::cout << "Lives: " << m_lives << std::endl;
		m_lives = m_lives - 1;
		//m_lives--;
		
	}
	
	if (m_lives == 0)
	{
		m_lives = -1;
		std::cout << "Dead Kev" << std::endl;
		return true;
	}
	return true;
}

bool UI::Update_Inventory()
{
	m_collectibles++;
	return true;
}

bool UI::Update_Health()
{
	m_health--; // change this to increase if collide with healthpack, decrease when collide with enemy/ enemy projectile
	return true;
}

bool UI::Update_Ammo()
{
	m_ammunition--; // change this to increase if collide with ammo pack, decrease when shoot weapon that requires ammo.
	return true;
}

bool UI::Display()
{
	if (m_ui_success == false)
	{
		std::cout << "UI has ran successfully " << std::endl;
		m_ui_success = true;
		return true;
	}
}

bool UI::Flicker()
{
	//rect->toggle_visible(true);
	
	return true;
}