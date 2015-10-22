#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	//somehow set the position of the overlay??

	new_player = new Player("images/player_placeholder.png", 1, 1, "Player", 100, 100, 100, 5);
	new_player->transform->set_current_position(10, 10);

	m_play_screen_ui = new UI_Play_Screen(1, new_player->get_character_health(), 0, new_player->get_lives(), 0, new_player->get_character_name());


}

void Game::Logic()
{
	//Run every function to be used.
	
}

void Game::Draw()
{
	//new_player->transform->Lerp_Positions();
	//new_player->transform->Lerp_To(new Vector2{ 200, 200 }, 0.01, 1);
	//new_ui->Display(); // someone needs to look into the UI Display not sure what to do
	new_player->transform->Move_Between();
	new_player->sprite->update_everything();
	m_play_screen_ui->Display();
}