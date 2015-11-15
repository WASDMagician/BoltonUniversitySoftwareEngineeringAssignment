#include "Level.h"


Level::Level()
:char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name("")
{
	char_fac = new Character_Factory_Implementation();
	pickup_fac = new Pick_Objects_Factory_Implementation();
	weapon_fac = new Weapon_Factory_Implementation();
}

Level::Level(std::string name)
: char_fac(NULL), m_areas(NULL), m_enemies(NULL), level_trigger(NULL), m_level_name(name)
{
	char_fac = new Character_Factory_Implementation();
	pickup_fac = new Pick_Objects_Factory_Implementation();
	weapon_fac = new Weapon_Factory_Implementation();
}

Level::~Level()
{
	delete char_fac;
	char_fac = NULL;

	delete pickup_fac;
	pickup_fac = NULL;

	delete weapon_fac;
	weapon_fac = NULL;

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

void Level::Move(int xAmount, int yAmount)
{
	for (auto &a : m_areas)
	{
		a->Move_By(xAmount, yAmount);
	}
	for (auto &e : m_enemies)
	{
		if (e != NULL)
		{
			e->Move_By(xAmount, yAmount);
		}
	}
	for (auto &c : m_pickables)
	{
		c->Move_By(xAmount, yAmount);
	}
	for (auto &d : m_weapons)
	{
		d->Move_By(xAmount, yAmount);
	}
	level_trigger->Move_By(xAmount, yAmount);
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
	for (auto &w : m_weapons)
	{
		w->update_everything();
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

std::vector<Weapon*> Level::get_weapons()
{
	return m_weapons;
}