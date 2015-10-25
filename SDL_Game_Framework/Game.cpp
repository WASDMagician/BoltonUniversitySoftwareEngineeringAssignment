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
	
	inventory = new Inventory("images/inv_slot.png", 1, 9);	
	CURRENT_STATE = START_GAME;
}




void Game::Logic()
{
	//Run every function to be used.
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
}

void Game::Logic_Play()
{
}

void Game::Logic_Pause()
{
}

void Game::Logic_End()
{
}




void Game::OnKeyPressed()
{
	switch (CURRENT_STATE)
	{
	case (START_GAME) :
		Handle_Start_Keys();
		break;
	case(PLAY_GAME) :
		Handle_Play_Keys();
		break;
	case(PAUSE_GAME) :
		Handle_Pause_Keys();
		break;
	case(END_GAME) :
		Handle_End_Keys();
		break;
	}
}

void Game::Handle_Start_Keys()
{
}

void Game::Handle_Play_Keys()
{
}

void Game::Handle_Pause_Keys()
{
}

void Game::Handle_End_Keys()
{
}





void Game::Draw()
{
	switch (CURRENT_STATE)
	{
	case (START_GAME) :
		Draw_Start();
		break;
	case(PLAY_GAME) :
		Draw_Play();
		break;
	case(PAUSE_GAME) :
		Draw_Pause();
		break;
	case(END_GAME) :
		Draw_End();
		break;
	}
}

void Game::Draw_Start()
{
}

void Game::Draw_Play()
{
	inventory->Draw();
}

void Game::Draw_Pause()
{
}

void Game::Draw_End()
{
}
