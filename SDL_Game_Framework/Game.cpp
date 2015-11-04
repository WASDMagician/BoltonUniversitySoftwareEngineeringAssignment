#include "Game.h"
#include "Character_Factory_Implementation.h"
#include "Weapon_Factory_Implementation.h"

Character_Factory_Implementation* character_factory;
Weapon_Factory_Implementation* weapon_factory;

Game::Game()
{
	TTF_Init();
}


Game::~Game()
{
	delete ogre;
}

void Game::Setup()
{
	character_factory = new Character_Factory_Implementation();
	ogre = character_factory->Make_Character(OGRE);
	jesus = character_factory->Make_Character(JESUS);
	player = character_factory->Make_Character(PLAYER);

	weapon_factory = new Weapon_Factory_Implementation();
	crossbow = weapon_factory->Make_Weapon(CROSSBOW);
	great_axe = weapon_factory->Make_Weapon(GREAT_AXE);
	/*
	splash_box = new Text_Boxes(new text_box_creation_variables{ "fonts/game_font.ttf", 28, new SDL_Color({ 255, 0, 0 }),
		new SDL_Color({ 0, 255, 255 }), 20, 20, { "test 1", "test 2" } });
		*/
	inventory = new Inventory("images/inv_slot.png", 1, 9);
<<<<<<< HEAD
=======
	player = new Player(new creation_variables{ "images/alien.bmp", 2, 3, "player test", 2, 2, 2, 200, "Player" });
	ogre = new Enemy(new creation_variables{ "images/fish.bmp", 1, 8, "enemy test", 2, 2, 2, 200, "Enemy" });
	clown = new NPC_Hinter(new creation_variables{ "images/clown.png", 1, 1, "npc test", 0, 0, 1000, 0, "NPC" });
	Vector2 PointA;
	PointA.x = 10;
	PointA.y = 10;
	Vector2 PointB;
	PointB.x = 100;
	PointB.y = 100;
	clown->set_points(PointA, PointB);
	ogre->serialize_character();
	player->serialize_character();
	clown->serialize_character();
	
	CURRENT_STATE = START_GAME;
}
>>>>>>> refs/remotes/origin/master

	Run();
}

void Game::Run()
{
	splash = new Start_Menu_Splash(this, "images/splash1.png");
<<<<<<< HEAD
	splash->Run();
	splash = new Play_Screen(this, "images/splash2.png");
	splash->Run();
	splash = new End_Menu_Splash(this, "images/splash1.png");
	splash->Run();
}
=======
	splash->Start();
	CURRENT_STATE = PLAY_GAME;
}

void Game::Logic_Play()
{
	//actual game logic here
	clown->move();
}

void Game::Logic_Pause()
{
	splash = new Pause_Menu_Splash(this, "images/pause_menu_splash_temp.png");
	splash->Start();
	CURRENT_STATE = PLAY_GAME;
}

void Game::Logic_End()
{
	//switch to end splash
	splash = new End_Menu_Splash(this, "images/splash2.png");
	splash->Start();
}

void Game::OnKeyPressed()
{
	switch (CURRENT_STATE)
	{
	case(PLAY_GAME) :
		Handle_Play_Keys();
		break;
	default:
		break;
	}
}

void Game::Handle_Play_Keys()
{
	if (keyDown == SDLK_p)
	{
		printf("Pausing\n");
		CURRENT_STATE = END_GAME;
		Logic_Pause();
	}
}

void Game::RenderHUD()
{ // this kind of stuff i imagine should be dealt with in the UI but for now it can be here until Text boxes work
	int stringSize = 0;
	int player_health = player->get_health();
	stringSize = Print("Health:", 1, 1, WHITE);
	stringSize = Print(player_health, stringSize + 1, 1, WHITE);

	int stringSize2 = 99;
	int enemy_health = ogre->get_health();
	Print("Enemy Health: ", 1, 100, WHITE);
	Print(enemy_health, stringSize2 +10, 100, WHITE);

}

void Game::Draw()
{
	switch (CURRENT_STATE)
	{
	case(PLAY_GAME) :
		Draw_Play();
		break;

	default:
		break;
	}
}

void Game::Draw_Play()
{
	inventory->Draw();
	player->render();
	ogre->render();
	clown->render();
	RenderHUD();

}
>>>>>>> refs/remotes/origin/master
