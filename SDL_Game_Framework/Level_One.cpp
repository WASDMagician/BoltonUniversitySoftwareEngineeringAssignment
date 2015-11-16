#include "Level_One.h"


Level_One::Level_One()
:Level()
{
	Setup();
}

Level_One::Level_One(std::string name)
:Level(name)
{
	Setup();
}

Level_One::~Level_One()
{
	for (auto &c : m_areas)
	{
		delete c;
		c = NULL;
	}
	m_areas.clear();

	for (auto &e : m_enemies)
	{
		delete e;
		e = NULL;
	}
	m_enemies.clear();
}

void Level_One::Setup()
{
	AW_Sprite_Interface *area_one = new AW_Sprite_Interface("images/area1.png", 1, 1, 1);
	AW_Sprite_Interface *area_two = new AW_Sprite_Interface("images/area2.png", 1, 1, 1);
	AW_Sprite_Interface *area_three = new AW_Sprite_Interface("images/area3.png", 1, 1, 1);
	AW_Sprite_Interface *area_four = new AW_Sprite_Interface("images/area4.png", 1, 1, 1);
	AW_Sprite_Interface *area_five = new AW_Sprite_Interface("images/area5.png", 1, 1, 1);
	
	area_one->set_world_position_x(-(float)area_one->get_width());
	area_three->set_world_position_y(-(float)area_three->get_height());
	area_four->set_world_position_y((float)area_four->get_height());
	area_five->set_world_position_x((float)area_five->get_width());

	m_areas.push_back(area_one);
	m_areas.push_back(area_two);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);

	Character *enemy = char_fac->Make_Character(OGRE);
	enemy->set_world_position(500, 500);
	enemy->Add_Patrol_Position(new Vector2<float, float>(10, 20));
	enemy->Add_Patrol_Position(new Vector2<float, float>(100, 100));
	m_enemies.push_back(enemy);

	Character *enemy2 = char_fac->Make_Character(JESUS);
	enemy2->set_world_position(750,750);
	enemy2->Add_Patrol_Position(new Vector2<float, float>(10, 20));
	enemy2->Add_Patrol_Position(new Vector2<float, float>(100, 100));
	m_enemies.push_back(enemy2);

	Character *npc1 = char_fac->Make_Character(CLOWN);
	npc1->set_world_position(-350, 0);
	npc1->Add_Patrol_Position(new Vector2<float, float>(10, 20));
	npc1->Add_Patrol_Position(new Vector2<float, float>(100, 100));
	m_npcs.push_back(npc1);

	for (auto &a : m_areas)
	{
		for (int i = 0; i < 10; i++)
		{
			Pickup_Objects *coin = pickup_fac->Make_Object(COIN);
			coin->Randomize_Position((int)a->get_x(), (int)a->get_width(), (int)a->get_y(), (int)a->get_height());
			m_pickables.push_back(coin);
		}
		Weapon *pickaxe = weapon_fac->Make_Weapon(GREAT_AXE);
		pickaxe->Randomize_Position((int)a->get_x(), (int)a->get_width(), (int)a->get_y(), (int)a->get_height());
		m_weapons.push_back(pickaxe);
	}
	level_trigger = new AW_Sprite_Interface("images/level_trigger.png", 1, 1, 1);
}