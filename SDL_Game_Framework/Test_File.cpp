#include "UnitTest++\src\UnitTest++.h"
#include "Character_Factory_Implementation.h"
#include "Pick_Objects_Factory_Implementation.h"
#include "Weapon_Factory_Implementation.h"
#include "Weapon.h"
#include "Sword.h"
#include "Great_Axe.h"

#include "Test_Level_One.h"
#include "Test_Level_Two.h"
#include "Test_Level_Three.h"

#include "Splash_Screen.h"
#include "Start_Menu_Splash.h"
#include "Play_Screen.h"
#include "End_Menu_Splash.h"

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
	TEST(AW_SPRITE_INTERFACE)
	{

	}

	TEST(CHARACTER)
	{

	}

	TEST(PLAYER)
	{

	}

	TEST(ENEMY)
	{

	}

	TEST(NPC)
	{

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
	TEST(SPLASH_SCREEN)
	{
	}

	TEST(START_MENU)
	{
	}

	TEST(PLAY_SCREEN)
	{
	}

	TEST(END_MENU)
	{
	}
}

SUITE(UI_TEST)
{
	TEST(UI_BASE)
	{
	}

	TEST(UI_PLAY_SCREEN)
	{
	}
}

SUITE(MISC_TEST)
{
	TEST(TEXT_BOX)
	{
			
	}
}