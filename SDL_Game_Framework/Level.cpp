#include "Level.h"


Level::Level()
:char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name("")
{
	char_fac = new Character_Factory_Implementation();
	pickup_fac = new Pick_Objects_Factory_Implementation();
}

Level::Level(std::string name)
: char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name(name)
{
	char_fac = new Character_Factory_Implementation();
	pickup_fac = new Pick_Objects_Factory_Implementation();
}

Level::~Level()
{
	printf("Destroctor called on level: %s\n", m_level_name);
	delete char_fac;
	char_fac = NULL;

	delete pickup_fac;
	pickup_fac = NULL;

	for (auto &a : m_areas)
	{
		delete a;
		a = NULL;
	}
	m_areas.clear();

	for (auto &e : m_enemies)
	{
		delete e;
		e = NULL;
	}
	m_enemies.clear();

	delete level_trigger;
	level_trigger = NULL;
}

bool Level::set_level_name(std::string name)
{
	m_level_name = name;
	return m_level_name == name;
}

std::string Level::get_level_name()
{
	return m_level_name;
}

void Level::Render()
{
	for (auto &a : m_areas)
	{
		if (a != NULL)
		{
			a->update_everything();
		}
	}
	for (size_t i = 0; i < m_enemies.size(); i++)
	{
		if (m_enemies[i] != NULL)
		{
			m_enemies[i]->update_everything();
		}
	}
	for (auto &p : m_pickables)
	{
		p->update_everything();
	}
	level_trigger->update_everything();
}

AW_Sprite_Interface* Level::get_trigger()
{
	return level_trigger;
}

std::vector<Character*> Level::get_enemies()
{
	return m_enemies;
}

std::vector<Pickup_Objects*> Level::get_pickables()
{
	return m_pickables;
}