#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	new_player = new Player("images/player_placeholder.png", 1, 1, "Player", 100, 100, 100);
}

void Game::Logic()
{
	
}

void Game::Draw()
{
	//new_player->transform->Move_Between();
	new_player->sprite->update_everything();
}