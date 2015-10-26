#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	TTF_Init();
	splash_box = new Text_Boxes(new text_box_creation_variables{ "fonts/game_font.ttf", 28, new SDL_Color({ 255, 0, 0 }),
		new SDL_Color({ 0, 255, 255 }), 20, 20, { "test 1", "test 2" } });
	inventory = new Inventory("images/inv_slot.png", 1, 9);

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
	splash->start();
	CURRENT_STATE = PLAY_GAME;
}

void Game::Logic_Play()
{
	//actual game logic here
}

void Game::Logic_Pause()
{
}

void Game::Logic_End()
{
	//switch to end splash
	splash = new End_Menu_Splash(this, "images/splash2.png");
	splash->start();
}




void Game::OnKeyPressed()
{
	switch (CURRENT_STATE)
	{
	case(PLAY_GAME) :
		Handle_Play_Keys();
		break;
	case(PAUSE_GAME) :
		Handle_Pause_Keys();
		break;
	default:
		break;
	}
}

void Game::Handle_Play_Keys()
{
}

void Game::Handle_Pause_Keys()
{
}



void Game::Draw()
{
	switch (CURRENT_STATE)
	{
	case(PLAY_GAME) :
		Draw_Play();
		break;
	case(PAUSE_GAME) :
		Draw_Pause();
		break;
	default:
		break;
	}
}

void Game::Draw_Play()
{
	inventory->Draw();
}

void Game::Draw_Pause()
{
}