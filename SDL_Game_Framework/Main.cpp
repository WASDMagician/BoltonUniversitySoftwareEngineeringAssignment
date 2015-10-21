#include "Game.h"
#include <iostream>

int main(int argc, char *argv[])
{
	GameBase::InitSDL(640, 480);
	Game* game = new Game();
	game->Setup();
	game->Start();

	SAFE_DELETE_PTR(game);
	return 0;
}