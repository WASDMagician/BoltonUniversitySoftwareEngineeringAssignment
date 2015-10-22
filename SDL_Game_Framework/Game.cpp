#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	new_player = new Player(new creation_variables{"images/alien.bmp", 2, 3, "player test", 2, 2, 2, 200});
	new_enemy = new Enemy(new creation_variables{ "images/player_placeholder.png", 1, 1, "enemy test", 2, 2, 2, 200 });
	new_ogre = new Enemy(new creation_variables{ "images/Fish.bmp", 1, 8, "ogre test", 2, 2, 2, 200 });
	


}

void Game::Logic()
{
	//Run every function to be used.
	new_player->sprite->auto_animate();
	new_ogre->sprite->auto_animate();
}

void Game::Draw()
{
	new_player->transform->Move_Between();
	new_player->sprite->update_everything();
	new_enemy->sprite->update_everything();
	new_ogre->sprite->update_everything();
}