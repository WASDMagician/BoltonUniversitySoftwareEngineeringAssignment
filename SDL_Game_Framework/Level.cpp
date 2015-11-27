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

void Level::Move_All(int xAmount, int yAmount)
{
	Move(xAmount, yAmount, m_areas);
	Move(xAmount, yAmount, m_enemies);
	Move(xAmount, yAmount, m_weapons);
	Move(xAmount, yAmount, m_npcs);
	Move(xAmount, yAmount, m_pickables);
	level_trigger->Move_By(xAmount, yAmount);
}

template<typename T>
void Level::Move(int xAmount, int yAmount, std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Move_By(xAmount, yAmount);
	}
}

void Level::Revert_All()
{
	Revert(m_areas);
	Revert(m_enemies);
	Revert(m_weapons);
	Revert(m_npcs);
	Revert(m_pickables);
	level_trigger->Revert_Position();
}

template<typename T>
void Level::Revert(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Revert_Position();
	}

	level_trigger->Revert_Position();
}

void Level::Render_All()
{
	Render(m_areas);
	Render(m_enemies);
	Render(m_weapons);
	Render(m_npcs);
	Render(m_pickables);
	level_trigger->Render();
}

template<typename T>
void Level::Render(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Render();
	}

	level_trigger->Render();
}

void Level::Reset_All_Positions()
{
	Reset_Positions(m_areas);
	Reset_Positions(m_enemies);
	Reset_Positions(m_weapons);
	Reset_Positions(m_npcs);
	Reset_Positions(m_pickables);
	level_trigger->Move_To_Spawn();
}

template<typename T>
void Level::Reset_Positions(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Move_To_Spawn();
	}

	level_trigger->Move_To_Spawn();
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