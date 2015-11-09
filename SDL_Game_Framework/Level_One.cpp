#include "Level_One.h"


Level_One::Level_One()
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
	AW_Sprite_Interface *area_one = new AW_Sprite_Interface("images/area1.png", 1, 1);
	AW_Sprite_Interface *area_two = new AW_Sprite_Interface("images/area2.png", 1, 1);
	AW_Sprite_Interface *area_three = new AW_Sprite_Interface("images/area3.png", 1, 1);
	AW_Sprite_Interface *area_four = new AW_Sprite_Interface("images/area4.png", 1, 1);
	AW_Sprite_Interface *area_five = new AW_Sprite_Interface("images/area5.png", 1, 1);
	
	area_one->set_world_position_x(-area_one->get_width());
	area_three->set_world_position_y(-area_three->get_height());
	area_four->set_world_position_y(area_four->get_height());
	area_five->set_world_position_x(area_five->get_width());

	m_areas.push_back(area_one);
	m_areas.push_back(area_two);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);

	Character *enemy = char_fac->Make_Character(OGRE);
	enemy->Add_Patrol_Position(new Vector2<int, int>(10, 20));
	enemy->Add_Patrol_Position(new Vector2<int, int>(100, 100));
	m_enemies.push_back(enemy);
}

void Level_One::Move(int xAmount, int yAmount)
{
	for (auto &a : m_areas)
	{
		a->Move_By(xAmount, yAmount);
	}
	for (auto &e : m_enemies)
	{
		e->Move_By(xAmount, yAmount);
	}
}

void Level_One::Move_Enemies()
{
	for (auto &e : m_enemies)
	{
		e->Move_Between();
	}
}