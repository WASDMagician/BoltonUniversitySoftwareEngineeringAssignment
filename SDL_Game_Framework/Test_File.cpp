#include "Test_File.h"


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
		//we cannot directly test the Level base class as it acts as a backend for the inheriting Level classes and requires
		//information stored within those levels, therefore we will test the functionality made available in Level by using Level_One,
		//Level_One's additional functionality will be tested separately
		Character* test_char = new Player("images/player.png", 1, 1); //create a character to passed to level
		Level_One *test_level = new Level_One(test_char); //create level

		CHECK(test_level != NULL); //check that test_level has been created
		CHECK(test_level->get_level_number() == 1); //check that get_level returns the correct number
		CHECK(test_level->get_trigger() != NULL); //check that get_trigger returns something
		CHECK(test_level->get_enemies().size() != 0); //check that the Enemy vector contains enemies
		CHECK(test_level->get_npcs().size() != 0); //check that the NPC vector contains npcs
		CHECK(test_level->get_weapons().size() != 0); //check that the Weapon vector contains weapons
		CHECK(test_level->get_objects().size() != 0); //check that the Pickables vector contains objects

		std::vector<Character*> enemies = test_level->get_enemies();
		std::vector<Character*> npcs = test_level->get_npcs();
		std::vector<Weapon*> weapons = test_level->get_weapons();
		std::vector<Pickup_Objects*> objects = test_level->get_objects();

		test_level->Move_All_Characters(enemies, 0, 0);
		for (size_t e = 0; e < enemies.size(); e++)
		{
			CHECK_EQUAL(enemies[e]->get_x(), 0);
			CHECK_EQUAL(enemies[e]->get_y(), 0);
		}

		test_level->Move_All_Characters(npcs, 200, 200);
		for (size_t n = 0; n < npcs.size(); n++)
		{
			CHECK_EQUAL(npcs[n]->get_x(), 200);
			CHECK_EQUAL(npcs[n]->get_y(), 200);
		}

		test_level->Move_All_Objects(objects, 400, 400);
		for (size_t o = 0; o < objects.size(); o++)
		{
			CHECK_EQUAL(objects[o]->get_x(), 400);
			CHECK_EQUAL(objects[o]->get_y(), 400);
		}

		test_level->Move_All_Weapons(weapons, 600, 600);
		for (size_t w = 0; w < weapons.size(); w++)
		{
			CHECK_EQUAL(weapons[w]->get_x(), 600);
			CHECK_EQUAL(weapons[w]->get_y(), 600);
		}

		//free used memory
		delete test_char;
		test_char = NULL;
		delete test_level;
		test_level = NULL;
	}

	TEST(LEVEL_ONE)
	{
		Character* test_char = new Player("images/player.png", 1, 1);
		Level_One *test_level = new Level_One(test_char);
	}

	TEST(LEVEL_TWO)
	{
	}

	TEST(LEVEL_THREE)
	{
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