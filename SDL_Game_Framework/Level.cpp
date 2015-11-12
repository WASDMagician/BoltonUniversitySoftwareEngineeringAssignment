#include "Level.h"


Level::Level()
:char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name("")
{
	char_fac = new Character_Factory_Implementation();
}

Level::Level(std::string name)
: char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name(name)
{
	char_fac = new Character_Factory_Implementation();
}

Level::~Level()
{
	printf("Destroctor called on level: %s\n", m_level_name);
	delete char_fac;
	char_fac = NULL;

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
		a->update_everything();
	}
	for (auto &e : m_enemies)
	{
		e->update_everything();
	}
	level_trigger->update_everything();
}

AW_Sprite_Interface* Level::get_trigger()
{
	return level_trigger;
}