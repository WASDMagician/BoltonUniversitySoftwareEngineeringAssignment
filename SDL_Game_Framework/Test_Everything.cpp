#include "Game_Object.h"
#include "UnitTest++\src\UnitTest++.h"

#include "Enemy.h"
#include "Ogre.h"
#include "Player.h"

SUITE(Character_Tests)
{
	TEST(Enemy_Class_Test)
	{
		Enemy* test_enemy = new Enemy(new creation_variables{ "images/player_placeholder.png", 1, 1, "Test_Enemy", 100, 50, 20, 200 });
		CHECK_EQUAL(true, test_enemy != NULL);
		CHECK_EQUAL(true, test_enemy->sprite != NULL);
		CHECK_EQUAL(true, test_enemy->transform != NULL);
		std::cout << test_enemy->transform->get_current_position().x << " " << test_enemy->transform->get_current_position().y << std::endl;
		Vector2 pre_position = test_enemy->transform->get_current_position();
		test_enemy->transform->Increment_Move(10, 10);
		Vector2 post_position = test_enemy->transform->get_current_position();
		
		system("pause");

		CHECK_EQUAL(true, pre_position != post_position);
	}
	TEST(Ogre_Class_Test)
	{
		Enemy* test_ogre = new Ogre(new creation_variables{ "images/player_placeholder.png", 1, 1, "Test_Ogre", 100, 50, 20, 200 });
		CHECK_EQUAL(true, test_ogre != NULL);
		CHECK_EQUAL(true, test_ogre->sprite != NULL);
		CHECK_EQUAL(true, test_ogre->transform != NULL);
		CHECK_EQUAL(true, test_ogre->transform->Move(10, 10));
	}
	TEST(Player_Class_Test)
	{
		Player* test_player = new Player(new creation_variables{ "images/player_placeholder.png", 1, 1, "Test_Player", 100, 50, 20, 200 });
		CHECK_EQUAL(true, test_player != NULL);
		CHECK_EQUAL(true, test_player->sprite != NULL);
		CHECK_EQUAL(true, test_player->transform != NULL);
		CHECK_EQUAL(true, test_player->transform->Move(10, 10));
	}
}