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
	new_player->transform->set_position(10, 10);
	new_player->transform->Add_Positions(new Vector2{ 50, 50 });
	new_player->transform->Add_Positions(new Vector2{ 200, 200 });


}

void Game::Logic()
{
	
}

void Game::Draw()
{
	new_player->transform->Lerp_Positions();
	new_player->sprite->update_everything();
}