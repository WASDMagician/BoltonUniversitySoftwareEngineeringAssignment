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

	Run();
}

void Game::Run()
{
	splash = new Start_Menu_Splash(this, "images/splash1.png");
	splash->Run();
	splash = new Play_Screen(this, "images/splash2.png");
	splash->Run();
	splash = new End_Menu_Splash(this, "images/splash1.png");
	splash->Run();
}
