#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	new_ui = new UI(0, 100, 15, 5, 0, "John Cena"); // items, health, ammo, lives, score, name
	//somehow set the position of the overlay??

	new_player = new Player("images/player_placeholder.png", 1, 1, "Player", 100, 100, 100);
	new_player->transform->set_current_position(10, 10);


}

void Game::User_Interface()
{
	new_ui->Display(); // need to add somehow the position of all the infomation the UI stores around the playing area

	new_ui->Update_Lives(); // reduce lives
	
	new_ui->Update_Score(); // increment score
}

void Game::Logic()
{
	//Run every function to be used.
	User_Interface();
}

void Game::Draw()
{
<<<<<<< HEAD
	//new_player->transform->Lerp_Positions();
	new_player->transform->Lerp_To(new Vector2{ 200, 200 }, 0.01, 1);
=======
	//new_ui->Display(); // someone needs to look into the UI Display not sure what to do

	new_player->transform->Lerp_Positions();
>>>>>>> origin/master
	new_player->sprite->update_everything();
}