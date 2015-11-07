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
}

void Level_One::Setup()
{
	AW_Sprite_Interface *area_one = new AW_Sprite_Interface("images/area1.png", 1, 1);
	area_one->set_world_position_x(-800);
	AW_Sprite_Interface *area_two = new AW_Sprite_Interface("images/area2.png", 1, 1);
	AW_Sprite_Interface *area_three = new AW_Sprite_Interface("images/area3.png", 1, 1);
	area_three->set_world_position_y(-600);
	AW_Sprite_Interface *area_four = new AW_Sprite_Interface("images/area4.png", 1, 1);
	area_four->set_world_position_y(600);
	AW_Sprite_Interface *area_five = new AW_Sprite_Interface("images/area5.png", 1, 1);
	area_five->set_world_position_x(800);
	m_areas.push_back(area_one);
	m_areas.push_back(area_two);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);
	
}

void Level_One::Move(int xAmount, int yAmount)
{
	for (size_t i = 0; i < m_areas.size(); i++)
	{
		m_areas[i]->Move_By(xAmount, yAmount);
	}
}
