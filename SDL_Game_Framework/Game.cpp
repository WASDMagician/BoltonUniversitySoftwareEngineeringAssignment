#include "Game.h"
#include "Start_Menu_Splash.h"
#include "Play_Screen.h"
#include "End_Menu_Splash.h"

Game::Game()
{
	TTF_Init();
	credit_box = new Text_Box();
	credit_box->set_font("fonts/game_font.ttf", 30);
	credit_box->set_color(200, 0, 0);
	credit_box->set_box_color(255, 255, 255);
	credit_box->Position_Setting(true, 50, 50, 10, 10);
	credit_box->Add_Message("CREDITS\nJoseph Adams\nNiall Maple\nKyle Thomas\nEdward Hawksowrth");
	credit_box->Setup_Box();
	credit_box->set_rects();
}


Game::~Game()
{
	delete splash;
	splash = NULL;
	delete credit_box;
	credit_box = NULL;

}

void Game::Setup()
{
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

void Game::Draw()
{
	credit_box->Display();
}