#include "Level.h"


Level::Level()
	:m_char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), m_level_trigger(NULL), m_level_name("")
{
	m_char_fac = new Character_Factory_Implementation();
	m_pickup_fac = new Pick_Objects_Factory_Implementation();
	m_weapon_fac = new Weapon_Factory_Implementation();
}

Level::Level(std::string name)
: m_char_fac(NULL), m_areas(NULL), m_enemies(NULL), m_npcs(NULL), m_level_trigger(NULL), m_level_name(name)
{
	m_char_fac = new Character_Factory_Implementation();
	m_pickup_fac = new Pick_Objects_Factory_Implementation();
	m_weapon_fac = new Weapon_Factory_Implementation();
}

Level::~Level()
{
	delete m_char_fac;
	m_char_fac = NULL;

	delete m_pickup_fac;
	m_pickup_fac = NULL;

	delete m_weapon_fac;
	m_weapon_fac = NULL;

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

	delete m_level_trigger;
	m_level_trigger = NULL;
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
	m_level_trigger->Move_By(xAmount, yAmount);
}

template<typename T>
void Level::Move(int xAmount, int yAmount, std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Move_By(xAmount, yAmount);
		if (inputVector[i]->Has_Target())
		{
			inputVector[i]->Move_Toward();
			inputVector[i]->Increment_Target();
			inputVector[i]->Update_Target_Position(xAmount, yAmount);
		}
	}
}


void Level::Render_All()
{
	Render(m_areas);
	Render(m_enemies);
	Render(m_weapons);
	Render(m_npcs);
	Render(m_pickables);
	m_level_trigger->Render();
}

template<typename T>
void Level::Render(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Render();
	}

	m_level_trigger->Render();
}

void Level::Reset_All_Positions()
{
	Reset_Positions(m_areas);
	Reset_Positions(m_enemies);
	Reset_Positions(m_weapons);
	Reset_Positions(m_npcs);
	Reset_Positions(m_pickables);
	m_level_trigger->Move_To_Spawn();
}

template<typename T>
void Level::Reset_Positions(std::vector<T>inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		inputVector[i]->Move_To_Spawn();
	}

	m_level_trigger->Move_To_Spawn();
}


AW_Sprite_Interface* Level::get_trigger()
{
	return m_level_trigger;
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