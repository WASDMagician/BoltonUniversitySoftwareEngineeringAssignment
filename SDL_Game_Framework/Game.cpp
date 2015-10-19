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
	new_player->transform->set_current_position(10, 10);


}

void Game::Logic()
{
	
}

void Game::Draw()
{
	//new_player->transform->Lerp_Positions();
	new_player->transform->Lerp_To(new Vector2{ 200, 200 }, 0.01, 1);
	new_player->sprite->update_everything();
}