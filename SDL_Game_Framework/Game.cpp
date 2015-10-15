#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	new_player = new Player("images/alien.bmp", 3, 2, { 255, 0, 255 }, { 50, 50, 0 }, "Player", 100, 100, 100);
}

void Game::Logic()
{
	
}

void Game::Draw()
{
	new_player->Update();
}