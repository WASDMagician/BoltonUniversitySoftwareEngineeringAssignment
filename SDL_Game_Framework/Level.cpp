#include "Level.h"


Level::Level()
	:char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), level_trigger(NULL), m_level_name("")
{
	char_fac = new Character_Factory_Implementation();
	pickup_fac = new Pick_Objects_Factory_Implementation();
	weapon_fac = new Weapon_Factory_Implementation();
}

Level::Level(std::string name)
: char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), level_trigger(NULL), m_level_name(name)
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
	for (auto &n : m_npcs)
	{
		delete n;
		n = NULL;
	}
	m_enemies.clear();
	m_npcs.clear();

	delete level_trigger;
	level_trigger = NULL;
}

std::vector<AW_Sprite_Interface*>Level::get_areas()
{
	return m_areas;
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
	for (size_t a = 0; a < m_areas.size(); a++)
	{
		m_areas[a]->Move_By(xAmount, yAmount);
	}

	for (size_t e = 0; e < m_enemies.size(); e++)
	{
		m_enemies[e]->Move_By(xAmount, yAmount);
		m_enemies[e]->Update_Target_Position(xAmount, yAmount);
		if (m_enemies[e]->Has_Target())
		{
			if (!m_enemies[e]->In_Range(10))
			{
				m_enemies[e]->Move_Toward();
			}
		}
	}

	for (size_t p = 0; p < m_pickables.size(); p++)
	{
		m_pickables[p]->Move_By(xAmount, yAmount);
	}

	for (size_t w = 0; w < m_weapons.size(); w++)
	{
		m_weapons[w]->Move_By(xAmount, yAmount);
	}

	for (size_t n = 0; n < m_npcs.size(); n++)
	{
		m_npcs[n]->Move_By(xAmount, yAmount);
	}

	level_trigger->Move_By(xAmount, yAmount);
}

void Level::Revert()
{
	for (size_t a = 0; a < m_areas.size(); a++)
	{
		m_areas[a]->Revert_Position();	
	}

	for (size_t e = 0; e < m_enemies.size(); e++)
	{
		m_enemies[e]->Revert_Position();
	}

	for (size_t p = 0; p < m_pickables.size(); p++)
	{
		m_pickables[p]->Revert_Position();
	}

	for (size_t w = 0; w < m_weapons.size(); w++)
	{
		m_weapons[w]->Revert_Position();
	}

	for (size_t n = 0; n < m_npcs.size(); n++)
	{
		m_npcs[n]->Revert_Position();
	}

	level_trigger->Revert_Position();
}

void Level::Render()
{
	for (size_t a = 0; a < m_areas.size(); a++)
	{
		m_areas[a]->Render();
	}

	level_trigger->update_everything();

	for (size_t e = 0; e < m_enemies.size(); e++)
	{
		m_enemies[e]->Render();
	}
	
	for (size_t p = 0; p < m_pickables.size(); p++)
	{
		m_pickables[p]->Render();
	}

	for (size_t w = 0; w < m_weapons.size(); w++)
	{
		m_weapons[w]->Render();
	}

	for (size_t n= 0; n < m_npcs.size(); n++)
	{
		m_npcs[n]->Render();
	}
}

AW_Sprite_Interface* Level::get_trigger()
{
	return level_trigger;
}

std::vector<Character*> Level::get_enemies()
{
	return m_enemies;
}

std::vector<Character*> Level::get_npcs()
{
	return m_npcs;
}

std::vector<Pickup_Objects*> Level::get_pickables()
{
	return m_pickables;
}

std::vector<Weapon*> Level::get_weapons()
{
	return m_weapons;
}