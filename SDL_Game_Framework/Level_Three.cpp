#include "Level_Three.h"


Level_Three::Level_Three()
:Level()
{
	Setup();
}

Level_Three::Level_Three(Character* player)
:Level(player)
{
	Setup();
}

Level_Three::~Level_Three()
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

void Level_Three::Setup()
{
	m_level_number = 3;
	//create areas
	AW_Sprite_Interface *area_one = new AW_Sprite_Interface("images/area5.png", 1, 1, 1);
	AW_Sprite_Interface *area_two = new AW_Sprite_Interface("images/area3.png", 1, 1, 1);
	AW_Sprite_Interface *area_three = new AW_Sprite_Interface("images/StartingArea.png", 1, 1, 1);
	AW_Sprite_Interface *area_four = new AW_Sprite_Interface("images/area4.png", 1, 1, 1);
	AW_Sprite_Interface *area_five = new AW_Sprite_Interface("images/area1.png", 1, 1, 1);
	
	//set area and bound positions
	int area_offset = 30;
	area_one->set_world_position_x(-(float)area_one->get_width() + area_offset);
	area_one->set_spawn(-(float)area_one->get_width() + area_offset, 0);

	area_three->set_world_position_y(-(float)area_three->get_height() + area_offset);
	area_three->set_spawn(0, -(float)area_three->get_height() + area_offset);

	area_four->set_world_position_y((float)area_four->get_height() - area_offset);
	area_four->set_spawn(0, (float)area_four->get_height() - area_offset);

	area_five->set_world_position_x((float)area_five->get_width() - area_offset);
	area_five->set_spawn((float)area_five->get_width() - area_offset, 0);

	//add areas to area vector
	m_areas.push_back(area_one);
	m_areas.push_back(area_three);
	m_areas.push_back(area_four);
	m_areas.push_back(area_five);
	m_areas.push_back(area_two);

	//create characters
	Character *jesus = m_char_fac->Make_Character(JESUS); //create character
	jesus->set_variables(300, 30);
	jesus->Move_To(500, 500); //set character position
	jesus->set_spawn(jesus->get_x(), jesus->get_y());
	jesus->Add_Positions({ { 20, 20}, { 300, 20}, { 300, 300}, { 20, 300 } });
	jesus->set_target_position(0);
	jesus->set_display_box(false); //should character text_box be displayed
	m_enemies.push_back(jesus); //add character jesus list

	Character *ogre = m_char_fac->Make_Character(OGRE);
	ogre->set_variables(100, 20);
	ogre->Move_To(200, 200);
	ogre->set_spawn(ogre->get_x(), ogre->get_y());
	ogre->set_display_box(false);
	m_enemies.push_back(ogre);

	Character *centipede_one = m_char_fac->Make_Character(CENTIPEDE);
	centipede_one->set_variables(20, 2);
	centipede_one->Move_To(100, 100);
	centipede_one->set_spawn(centipede_one->get_x(), centipede_one->get_y());
	centipede_one->set_display_box(false);
	centipede_one->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(centipede_one);

	Character *centipede_two = m_char_fac->Make_Character(CENTIPEDE);
	centipede_two->set_variables(20, 2);
	centipede_two->Move_To(200, 200);
	centipede_two->set_spawn(centipede_two->get_x(), centipede_two->get_y());
	centipede_two->set_display_box(false);
	centipede_two->set_transparent_colour(255, 0, 255);
	m_enemies.push_back(centipede_two);

	Character *hinter = m_char_fac->Make_Character(CLOWN);
	hinter->Move_To(450, 50);
	hinter->set_spawn(hinter->get_x(), hinter->get_y());
	hinter->set_display_box(false);
	hinter->set_message("Collect all the coins\nand your way forward\nwill appear");
	m_npcs.push_back(hinter);

	Character *healer = m_char_fac->Make_Character(HEALER);
	healer->Move_To(420, 420);
	healer->set_spawn(healer->get_x(), healer->get_y());
	healer->set_message("You have been healed");
	m_npcs.push_back(healer);

	float area_margin_x = 100;
	float area_margin_y = 100;

	for (auto &area : m_areas)
	{
		for (int i = 0; i < 10; i++)
		{
			//place coins
			Pickup_Objects *coin = m_pickup_fac->Make_Object(COIN);
			coin->Randomize_Position((int)area->get_x(), (int)area->get_width(), (int)area->get_y(), (int)area->get_height());
			coin->set_spawn(coin->get_x(), coin->get_y());
			coin->set_value(10);
			m_pickables.push_back(coin);
		}
		//place weapons
		Weapon *pickaxe = m_weapon_fac->Make_Weapon(GREAT_AXE);
		pickaxe->Randomize_Position((int)area->get_x() + area_margin_x, (int)area->get_width() - area_margin_x, 
			(int)area->get_y() + area_margin_y, (int)area->get_height() - area_margin_y);
		pickaxe->set_spawn(pickaxe->get_x(), pickaxe->get_y());
		pickaxe->set_value(5);
		m_weapons.push_back(pickaxe);
	}

	m_level_trigger = new AW_Sprite_Interface("images/level_trigger.png", 1, 1, 1);
	m_level_trigger->set_spawn(m_level_trigger->get_x(), m_level_trigger->get_y());
	m_level_trigger->set_visibility(false);
}