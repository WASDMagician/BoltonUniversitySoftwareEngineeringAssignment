#include "Game.h"
#include "Game_Constants.h"
#include <iostream>

int main(int argc, char *argv[])
{
	GameBase::InitSDL(SCRN_WIDTH, SCRN_HEIGHT);
	Game* game = new Game();
	game->Setup();
	game->Start();

	SAFE_DELETE_PTR(game);
	return 0;
}