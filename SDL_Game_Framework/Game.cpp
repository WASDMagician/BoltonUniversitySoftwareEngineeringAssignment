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

	
}

void Game::Logic()
{
	//Run every function to be used.
	text_box->Update();
	new_enemy->Enemy_Movement();
}

void Game::Draw()
{
	text_box->Render_Text();
	new_player->transform->Move_Between();
	new_player->render();
	new_enemy->render();
	new_ogre->render();
	new_npc_shopkeeper->render();
	inventory->Draw();
}