#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	//new Player(PATH TO IMAGE, COLUMNS, ROWS, TRANSPARENT COLOUR, POSITIOn, NAME, HEALTH, DAMAGE, DEFENCE)
	new_player = new Player("images/player_placeholder.png", 1, 1, "Player", 100, 100, 100);
}

void Game::Logic()
{
	
}

void Game::Draw()
{
}