#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
	delete player;
	delete ogre;
}

void Game::Setup()
{
	TTF_Init();
	splash_box = new Text_Boxes(new text_box_creation_variables{ "fonts/game_font.ttf", 28, new SDL_Color({ 255, 0, 0 }),
		new SDL_Color({ 0, 255, 255 }), 20, 20, { "test 1", "test 2" } });
	inventory = new Inventory("images/inv_slot.png", 1, 9);
	player = new Player(new creation_variables{ "images/alien.bmp", 2, 3, "player test", 2, 2, 2, 200, "Player" });
	ogre = new Enemy(new creation_variables{ "images/fish.bmp", 1, 8, "enemy test", 2, 2, 2, 200, "Enemy" });
	ogre->serialize_character();
	player->serialize_character();
	projectile = new Projectile("images/bullet.png", 0, 0);

	CURRENT_STATE = START_GAME;
}

void Game::Logic()
{
	//Do not add any code here, add code to the respective functions (or in start_gae and end_game their respective splash classes)
	switch (CURRENT_STATE)
	{
	case (START_GAME) :
		Logic_Start();
		break;
	case(PLAY_GAME) :
		Logic_Play();
		break;
	case(PAUSE_GAME) :
		Logic_Pause();
		break;
	case(END_GAME) :
		Logic_End();
		break;
	}
}


void Game::Logic_Start()
{
	//switch to start splash
	splash = new Start_Menu_Splash(this, "images/splash1.png");
	splash->Start();
	CURRENT_STATE = PLAY_GAME;
}

void Game::Logic_Play()
{
	//actual game logic here
	Handle_Projectile();
	player->sprite->set_world_position(200, 200);

	//we need a for loop here for enemies to check their health
	if (ogre->get_health() <= 0)
	{
		//if they are dead, run some code here - eg. erase or something
	}
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
		CURRENT_STATE = PAUSE_GAME;
		system("pause");
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
	RenderHUD();

	for (int i = 0; i < proj_array.size(); i++)
	{
		//proj_array[i].update_everything();
		//projectile->update_everything();
	}
}