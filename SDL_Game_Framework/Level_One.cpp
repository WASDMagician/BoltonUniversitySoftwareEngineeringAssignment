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
	area_one->set_spawn(-(float)area_one->get_width(), 0);

	area_three->set_world_position_y(-(float)area_three->get_height());
	area_three->set_spawn(0, -(float)area_three->get_height());

	area_four->set_world_position_y((float)area_four->get_height());
	area_four->set_spawn(0, (float)area_four->get_height());

	area_five->set_world_position_x((float)area_five->get_width());
	area_five->set_spawn((float)area_five->get_width(), 0);

	//add areas to area vector
	m_areas.push_back(area_one);
	m_areas.push_back(area_two);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);

	//create characters
	Character *ogre = char_fac->Make_Character(OGRE); //create character
	ogre->set_variables(50, 10);
	ogre->Move_To(500, 500); //set character position
	ogre->set_spawn(500, 500);
	ogre->Add_Positions({ { 20, 20 }, { 100, 150 }, { 200, 400 }, { 500, 500 } });
	ogre->set_target_position(0);
	ogre->set_display_box(false); //should character text_box be displayed
	ogre->set_damage(10); //set character damage
	m_enemies.push_back(ogre); //add character ogre list

	Character *jesus = char_fac->Make_Character(JESUS);
	jesus->set_variables(100, 20);
	jesus->Move_To(750, 750);
	jesus->set_spawn(750, 750);
	jesus->set_display_box(false);
	m_enemies.push_back(jesus);

	Character *centipede_one = char_fac->Make_Character(CENTIPEDE);
	centipede_one->set_variables(20, 2);
	centipede_one->Move_To(100, 100);
	centipede_one->set_spawn(100, 100);
	centipede_one->set_display_box(false);
	centipede_one->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(centipede_one);

	Character *centipede_two = char_fac->Make_Character(CENTIPEDE);
	centipede_two->set_variables(20, 2);
	centipede_two->Add_Position({ 10, 20 });
	centipede_two->Move_To(200, 200);
	centipede_two->set_spawn(200, 200);
	centipede_two->set_display_box(false);
	centipede_two->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(centipede_two);

	Character *hinter = char_fac->Make_Character(CLOWN);
	hinter->Move_To(-350, 0);
	hinter->set_spawn(-350, 0);
	hinter->set_display_box(false);
	hinter->set_message("Collect all the coins\nand your way forward\nwill appear");
	m_npcs.push_back(hinter);

	Character *healer = char_fac->Make_Character(HEALER);
	healer->Move_To(420, 420);
	healer->set_spawn(420, 420);
	healer->set_message("You have been healed");
	m_npcs.push_back(healer);

	for (auto &area : m_areas)
	{
		for (int i = 0; i < 10; i++)
		{
			//place coins
			Pickup_Objects *coin = pickup_fac->Make_Object(COIN);
			coin->Randomize_Position((int)area->get_x(), (int)area->get_width(), (int)area->get_y(), (int)area->get_height());
			coin->set_spawn(coin->get_x(), coin->get_y());
			m_pickables.push_back(coin);
		}
		//place weapons
		Weapon *pickaxe = weapon_fac->Make_Weapon(GREAT_AXE);
		pickaxe->Randomize_Position((int)area->get_x(), (int)area->get_width(), (int)area->get_y(), (int)area->get_height());
		pickaxe->set_spawn(pickaxe->get_x(), pickaxe->get_y());
		m_weapons.push_back(pickaxe);
	}

	level_trigger = new AW_Sprite_Interface("images/level_trigger.png", 1, 1, 1);
	level_trigger->set_spawn(level_trigger->get_x(), level_trigger->get_y());
}