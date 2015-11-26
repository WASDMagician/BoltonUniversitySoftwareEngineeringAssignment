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
	for (auto &area: m_areas)
	{
		delete area;
		area = NULL;
	}
	m_areas.clear();

	for (auto &enemy : m_enemies)
	{
		delete enemy;
		enemy = NULL;
	}

	for (auto &npc : m_npcs)
	{
		delete npc;
		npc = NULL;
	}

	m_enemies.clear();
	m_npcs.clear();
}

void Level_One::Setup()
{

	//create areas
	AW_Sprite_Interface *area_one = new AW_Sprite_Interface("images/area1.png", 1, 1, 1);
	AW_Sprite_Interface *area_two = new AW_Sprite_Interface("images/StartingArea.png", 1, 1, 1);
	AW_Sprite_Interface *area_three = new AW_Sprite_Interface("images/area3.png", 1, 1, 1);
	AW_Sprite_Interface *area_four = new AW_Sprite_Interface("images/area4.png", 1, 1, 1);
	AW_Sprite_Interface *area_five = new AW_Sprite_Interface("images/area5.png", 1, 1, 1);
	
	//set area and bound positions
	area_one->set_world_position_x(-(float)area_one->get_width());


	area_three->set_world_position_y(-(float)area_three->get_height());

	area_four->set_world_position_y((float)area_four->get_height());
	area_five->set_world_position_x((float)area_five->get_width());

	//add areas to area vector
	m_areas.push_back(area_one);
	m_areas.push_back(area_two);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);

	//create characters
	Character *enemy = char_fac->Make_Character(OGRE); //create character
	enemy->Move_To(500, 500); //set character position
	
	enemy->set_display_box(false); //should character text_box be displayed
	enemy->set_damage(2); //set character damage
	m_enemies.push_back(enemy); //add character enemy list

	Character *enemy2 = char_fac->Make_Character(JESUS);
	enemy2->Move_To(750, 750);
	enemy2->set_display_box(false);
	m_enemies.push_back(enemy2);

	Character *enemy3 = char_fac->Make_Character(CENTIPEDE);
	enemy3->Move_To(100, 100);
	enemy3->set_display_box(false);
	enemy3->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(enemy3);

	Character *enemy4 = char_fac->Make_Character(CENTIPEDE);
	enemy4->Move_To(200, 200);
	enemy4->set_display_box(false);
	enemy4->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(enemy4);

	Character *npc1 = char_fac->Make_Character(CLOWN);
	npc1->Move_To(-350, 0);
	npc1->set_display_box(false);
	npc1->set_message("You are near to a \nsomething or \nother rune type thingy\n");
	m_npcs.push_back(npc1);

	Character *npc2 = char_fac->Make_Character(HEALER);
	npc2->Move_To(420, 420);
	npc2->set_message("You have been healed");
	m_npcs.push_back(npc2);

	for (auto &area : m_areas)
	{
		for (int i = 0; i < 10; i++)
		{
			//place coins
			Pickup_Objects *coin = pickup_fac->Make_Object(COIN);
			coin->Randomize_Position((int)area->get_x(), (int)area->get_width(), (int)area->get_y(), (int)area->get_height());
			m_pickables.push_back(coin);
		}
		//place weapons
		Weapon *pickaxe = weapon_fac->Make_Weapon(GREAT_AXE);
		pickaxe->Randomize_Position((int)area->get_x(), (int)area->get_width(), (int)area->get_y(), (int)area->get_height());
		m_weapons.push_back(pickaxe);
	}

	level_trigger = new AW_Sprite_Interface("images/level_trigger.png", 1, 1, 1);
}