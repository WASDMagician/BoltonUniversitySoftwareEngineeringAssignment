#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
	delete new_player;
	delete new_enemy;
	delete new_ogre;
	delete new_npc_shopkeeper;
}

void Game::Setup()
{
	TTF_Init();

	new_player = new Player(new creation_variables{"images/alien.bmp", 2, 3, "player test", 2, 2, 2, 200});
	new_enemy = new Enemy(new creation_variables{ "images/player_placeholder.png", 1, 1, "enemy test", 2, 2, 2, 200 });
	new_ogre = new Enemy(new creation_variables{ "images/Fish.bmp", 1, 8, "ogre test", 2, 2, 2, 200 });
	new_npc_shopkeeper = new NPC_Shopkeeper(new creation_variables{ "images/Fish.bmp", 1, 8, "ogre test", 2, 2, 2, 200 });

	text_box = new Text_Boxes();
	TTF_Font *font = TTF_OpenFont("fonts/game_font.ttf", 18);
	std::cout << font << std::endl;
	text_box->set_font(font);
	text_box->Setup_Message({"Multiline motherfuckers", "get vectored", "Pros", "Multilines", "Almost self contained", "Cons", 
		"No punctuation", "Need to sort out rects",	"a bit jagged", "Need to add timing", "each line creates a new surface",
	"not sure what the memory implications are", "this message adds about 3mb", "seems a bit much"});
	text_box->set_game(this);
	system("pause");
}

void Game::Logic()
{
	//Run every function to be used.
	SDL_Delay(50);
	text_box->Update();
}

void Game::Draw()
{
	//new_player->transform->Move_Between();
	//new_player->render();
	//new_enemy->render();
	//new_ogre->render();
	//new_npc_shopkeeper->render();
	text_box->Render_Text();
}