#include "Game_Object.h"
#include "UnitTest++\src\UnitTest++.h"

#include "Enemy.h"
#include "Ogre.h"
#include "Player.h"

SUITE(Character_Tests)
{
	TEST(Enemy_Class_Test)
	{
		Enemy* test_enemy = new Enemy(new creation_variables{ "images/player_placeholder.png", 1, 1, "Player_Name", 100, 50, 20, 200 });
		CHECK_EQUAL(true, test_enemy != NULL);
		CHECK_EQUAL(true, test_enemy->sprite != NULL);
		CHECK_EQUAL(true, test_enemy->transform != NULL);
		CHECK_EQUAL(true, test_enemy->transform->Move(10, 10));
	}
	TEST(Ogre_Class_Test)
	{
	}
	TEST(Player_Class_Test)
	{

	}
}