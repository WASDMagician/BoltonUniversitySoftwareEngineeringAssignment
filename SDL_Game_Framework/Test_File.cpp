#include "UnitTest++\src\UnitTest++.h"
#include "Character_Factory_Implementation.h"
#include "Player.h"

#include "Enemy.h"
#include "Centipede.h"
#include "Clown.h"
#include "Jesus.h"
#include "Ogre.h"

#include "NPC_Healer.h"
#include "NPC_Hinter.h"

#include "Pick_Objects_Factory_Implementation.h"

#include "Weapon_Factory_Implementation.h"
#include "Weapon.h"
#include "Sword.h"
#include "Great_Axe.h"

#include "Game.h"

#include "Test_Level_One.h"
#include "Test_Level_Two.h"
#include "Test_Level_Three.h"

#include "Test_AW_Sprite_Interface.h"

#include "Text_Box.h"

#include "UI_Play_Screen.h"

SUITE(FACTORY_TEST)
{
	TEST(CHARACTER_FACTORY)
	{
		Character *test_character = NULL; //character that Character_Factory_Implementation will create
		Character_Factory_Implementation *char_fac = new Character_Factory_Implementation(); //character_factory_implementation to test
		test_character = char_fac->Make_Character(PLAYER); //create player
		CHECK(test_character != NULL); //test player has been created
		//free used memory
		delete test_character;
		test_character = NULL;
		delete char_fac;
		char_fac = NULL;
	}

	TEST(OBJECT_FACTORY)
	{
		Pickup_Objects *test_object = NULL; //object that Pick_Objects_Factory_Implementation will create
		Pick_Objects_Factory_Implementation *obj_fac = new Pick_Objects_Factory_Implementation(); //pick_objects_factory_implementation to test
		test_object = obj_fac->Make_Object(COIN); //create object
		CHECK(test_object != NULL); //check object has been created
		//free used memory
		delete test_object;
		test_object = NULL;
		delete obj_fac;
		obj_fac = NULL;
	}

	TEST(WEAPON_FACTORY)
	{
		Weapon *test_weapon = NULL; //weapon that Weapon_Factory_Implementation will create
		Weapon_Factory_Implementation *weapon_fac = new Weapon_Factory_Implementation(); //weapon_factory_implementation to test
		test_weapon = weapon_fac->Make_Weapon(SWORD); //weapon_factory_implementation to test
		CHECK(test_weapon != NULL); //create weapon
		//free used memory
		delete test_weapon;
		test_weapon = NULL;
		delete weapon_fac;
		weapon_fac = NULL;
	}
}

SUITE(CHARACTER_TEST)
{
	TEST(CHARACTER)
	{
		Character* test_character = new Character("images/player.png", 1, 1, "testing message"); //create test character
		Character* test_opponent = new Character("images/player.png", 1, 1, "testing message the second"); //create test opponent
		test_character->set_variables(100, 20); //set test_character health and damage
		test_character->set_lives(3); //set test_character lives

		//check that return values match input values
		CHECK(test_character->get_health() == 100); 
		CHECK(test_character->get_damage() == 20);
		CHECK(test_character->get_lives() == 3);
		CHECK(test_character->get_message() == "testing message");

		//set opponent values
		test_opponent->set_variables(100, 100);
		test_opponent->set_lives(5);

		//test character attacking opponent
		test_character->Attack(test_opponent);
		CHECK(test_opponent->get_health() == 80);

		CHECK(test_character->Check_Alive() == true); //check that test_character is alive
		test_opponent->Attack(test_character); //have opponent attack character
		CHECK(test_character->get_health() == 0); //check that characters health is 0
		CHECK(test_character->Check_Alive() == false); //check that test_character is not alive

		//free used memory
		delete test_character;
		test_character = NULL;

		delete test_opponent;
		test_opponent = NULL;

	}

	TEST(PLAYER)
	{
		Player* test_player = new Player("images/player.png", 1, 1);
		CHECK(test_player != NULL);

		delete test_player;
		test_player = NULL;
	}

	TEST(ENEMY)
	{
		Enemy* test_enemy = new Enemy("images/alien.bmp", 3, 2);
		CHECK(test_enemy != NULL);

		delete test_enemy;
		test_enemy = NULL;
	}

	TEST(CENTIPEDE)
	{
		Centipede* test_enemy = new Centipede("images/centipede.png", 1, 1);
		CHECK(test_enemy != NULL);

		delete test_enemy;
		test_enemy = NULL;
	}

	TEST(CLOWN)
	{
		Clown* test_enemy = new Clown("images/clown.png", 1, 1);
		CHECK(test_enemy != NULL);

		delete test_enemy;
		test_enemy = NULL;
	}

	TEST(JESUS)
	{
		Centipede* test_enemy = new Centipede("images/jesus.bmp", 1, 1);
		CHECK(test_enemy != NULL);

		delete test_enemy;
		test_enemy = NULL;
	}

	TEST(OGRE)
	{
		Ogre* test_enemy = new Ogre("images/alien.bmp", 3, 2);
		CHECK(test_enemy != NULL);

		delete test_enemy;
		test_enemy = NULL;
	}

	TEST(NPC_HEALER)
	{
		NPC_Healer* test_npc = new NPC_Healer("images/healer.png", 1, 1, "get healed");
		Character* test_character = new Character("images/player.png", 1, 1, "");

		CHECK(test_npc != NULL);
		CHECK(test_character != NULL);

		test_character->set_variables(1, 50);
		test_npc->React(test_character);
		CHECK(test_character->get_health() == 100);

		delete test_npc;
		test_npc = NULL;
		delete test_character;
		test_character = NULL;
	}

	TEST(NPC_HINTER)
	{
		NPC_Hinter* test_npc = new NPC_Hinter("images/hinter1.png", 1, 1, "get hinted");

		CHECK(test_npc != NULL);

		delete test_npc;
		test_npc = NULL;
		

	}
}

SUITE(WEAPON_TEST)
{
	TEST(WEAPON)
	{
		Weapon *test_weapon = new Weapon("images/swords.bmp", 1, 1, 10); //create weapon
		CHECK(test_weapon != NULL); //check that weapon has been created
		CHECK_EQUAL(test_weapon->get_value(), 10); //check that weapon value has been set
		test_weapon->set_value(50); //change value
		CHECK_EQUAL(test_weapon->get_value(), 50); //check change value

		//free used memory
		delete test_weapon;
		test_weapon = NULL;
	}

	TEST(SWORD)
	{
		Sword *test_sword = new Sword("images/swords.bmp", 8, 1, 15); //create sword
		CHECK(test_sword != NULL); //check that sword has been created
		CHECK_EQUAL(test_sword->get_value(), 15); //check that sword value has been set
		test_sword->set_value(45); //change value
		CHECK_EQUAL(test_sword->get_value(), 45); //check change value

		delete test_sword;
		test_sword = NULL;
	}

	TEST(GREAT_AXE)
	{
		Great_Axe *great_axe = new Great_Axe("images/pickaxe.bmp", 12, 1, 15); //create great_axe
		CHECK(great_axe != NULL); //check that great_axe has been created
		CHECK_EQUAL(great_axe->get_value(), 15); //check that great_axe value has been set
		great_axe->set_value(45); //change value
		CHECK_EQUAL(great_axe->get_value(), 45); //check change value

		delete great_axe;
		great_axe = NULL;

	}
}

SUITE(LEVEL_TEST)
{
	TEST(LEVEL)
	{
		Character* test_character = new Character("images/player.png", 1, 1, "");
		Test_Level_One* test_level = new Test_Level_One(test_character);

		//carry out level logic
		test_level->Run_Level_Logic(0, 0);
		SDL_Delay(1000);
		test_level->Run_Level_Logic(0, 0);

		//test character and level creation
		CHECK(test_character != NULL);
		CHECK(test_level != NULL);

		//check that all items in level have been created

		//check vectors
		CHECK(test_level->get_areas().size() != 0);
		CHECK(test_level->get_npcs().size() != 0);
		CHECK(test_level->get_enemies().size() != 0);
		CHECK(test_level->get_objects().size() != 0);
		CHECK(test_level->get_weapons().size() != 0);

		//check factories
		CHECK(test_level->get_character_factory() != NULL);
		CHECK(test_level->get_object_factory() != NULL);
		CHECK(test_level->get_weapon_factory() != NULL);

		//check variables
		CHECK(test_level->get_area_offset() == 55);
		CHECK(test_level->get_level_numbe() == 1);

		CHECK(test_level->get_time() != 0);
		CHECK(test_level->get_current_time() != 0);
		CHECK(test_level->get_play_time() != 0);

		//add movement test here

		//collect coin test

		//collect weapon test

		delete test_character;
		test_character = NULL;
		delete test_level;
		test_level = NULL;
	}

	TEST(LEVEL_ONE)
	{
		Character* test_character = new Character("images/player.png", 1, 1, "");
		Test_Level_One* test_level = new Test_Level_One(test_character);

		//test character and level creation
		CHECK(test_character != NULL);
		CHECK(test_level != NULL);

		delete test_character;
		test_character = NULL;
		delete test_level;
		test_level = NULL;
	}

	TEST(LEVEL_TWO)
	{
		Character* test_character = new Character("images/player.png", 1, 1, "");
		Test_Level_Two* test_level = new Test_Level_Two(test_character);

		//test character and level creation
		CHECK(test_character != NULL);
		CHECK(test_level != NULL);


		delete test_character;
		test_character = NULL;
		delete test_level;
		test_level = NULL;
	}

	TEST(LEVEL_THREE)
	{
		Character* test_character = new Character("images/player.png", 1, 1, "");
		Test_Level_Three* test_level = new Test_Level_Three(test_character);

		//test character and level creation
		CHECK(test_character != NULL);
		CHECK(test_level != NULL);


		delete test_character;
		test_character = NULL;
		delete test_level;
		test_level = NULL;
	}
}

SUITE(SPLASH_SCREENS_TEST)
{
	//we cannot create automated tests for splash screen functionality as it requires running the actual game
}

SUITE(UI_TEST)
{
	TEST(UI_PLAY_SCREEN)
	{
		Character* test_character = new Character("images/player.png", 1, 1, ""); //create test character
		UI_Play_Screen* test_UI; //create test ui
		test_UI = test_UI->get_instance(); //instantiate ui singleton
		test_UI->set_character(test_character); //set character
		CHECK(test_UI != NULL); //check that ui has been created
		CHECK(test_UI->get_character() == test_character); //check that the character that ui returns matches the one given

		//free used memory
		delete test_character;
		test_character = NULL;
		delete test_UI;
		test_UI = NULL;
	}
}

SUITE(MISC_TEST)
{
	TEST(AW_SPRITE_INTERFACE)
	{
		Test_AW_Sprite_Interface *test_aw_sprite_interface = new Test_AW_Sprite_Interface("images/player.png", 1, 1); //create sprite
		CHECK(test_aw_sprite_interface != NULL); //check sprite has been created

		test_aw_sprite_interface->Add_Positions({ { 0, 0 }, { 10, 10 } }); //add position vector to sprite
		CHECK(test_aw_sprite_interface->get_positions().size() == 2); //check that positions have been added
		test_aw_sprite_interface->Add_Position({ 500, 500 }); //add single position to sprite
		CHECK(test_aw_sprite_interface->get_positions().size() == 3) //check that positions have been updated
			;
		CHECK(test_aw_sprite_interface->get_x() == 0); //check that initial value is as it should be
		CHECK(test_aw_sprite_interface->get_y() == 0); 
		test_aw_sprite_interface->Move_By(10, 10); //move by 10
		CHECK(test_aw_sprite_interface->get_x() == 10); //check that move has taken place
		CHECK(test_aw_sprite_interface->get_y() == 10);

		test_aw_sprite_interface->set_target_position(0); //set target position from list
		test_aw_sprite_interface->Move_Toward(); //move toward target position
		CHECK(test_aw_sprite_interface->get_x() != 10); //check that position has changed
		CHECK(test_aw_sprite_interface->get_y() != 10);

		test_aw_sprite_interface->set_spawn(0, 0); //set the spawn position
		test_aw_sprite_interface->Move_To_Spawn(); //move to spawn
		CHECK(test_aw_sprite_interface->get_x() == 0 && test_aw_sprite_interface->get_y() == 0); // that move took place

		//free used memory
		delete test_aw_sprite_interface;
		test_aw_sprite_interface = NULL;


	}

	TEST(TEXT_BOX)
	{
			
	}
}