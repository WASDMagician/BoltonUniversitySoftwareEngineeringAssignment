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
}

void Game::Setup()
{
	projectile = new Projectile("images/bullet.png", 0, 0);
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
	//CURRENT_STATE = PLAY_GAME;
}

/*
void Game::Handle_Play_Keys()
{
	if (keyDown == SDLK_p)
	{
		printf("Pausing\n");
		CURRENT_STATE = END_GAME;
		Logic_Pause();
	}

	float player_x = player->sprite->get_x();
	float player_y = player->sprite->get_y();

	if (keyDown == SDLK_UP)
	{
		//1
		projectile = new Projectile("images/bullet.png", 1, 1);
		projectile->direction = 1;
		projectile->set_world_position(player_x, player_y);
		proj_array.push_back(*projectile);
	}
	if (keyDown == SDLK_DOWN)
	{
		//2
		projectile = new Projectile("images/bullet.png", 1, 1);
		projectile->direction = 2;
		projectile->set_world_position(player_x, player_y);
		proj_array.push_back(*projectile);
	}
	if (keyDown == SDLK_LEFT)
	{
		//3
		projectile = new Projectile("images/bullet.png", 1, 1);
		projectile->direction = 3;
		projectile->set_world_position(player_x, player_y);
		proj_array.push_back(*projectile);
	}
	if (keyDown == SDLK_RIGHT)
	{
		//4
		projectile = new Projectile("images/bullet.png", 1, 1);
		projectile->direction = 4;
		projectile->set_world_position(player_x, player_y);
		proj_array.push_back(*projectile);
	}

	//simple player blocking for now - perhaps we could make this more fun?
	if (keyDown == SDLK_LCTRL || keyDown == SDLK_RCTRL)
	{
		player->is_blocking = true;
		//if player is blocking enemy cant hit
	}
	else if (keyUp == SDLK_LCTRL || keyUp == SDLK_RCTRL)
	{
		player->is_blocking = false;
		//if player isnt blocking enemy can hit
	}
}

void Game::Handle_Projectile()
{
	std::cout << player->is_blocking << std::endl;

	for (int i = 0; i < proj_array.size(); i++)
	{
		//proj_array[i].Update();
	}
}
*/