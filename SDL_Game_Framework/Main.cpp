#include "Game.h"
#include "Game_Constants.h"
#include "Test_All.h"
#include <iostream>



int main(int argc, char *argv[])
{
	GameBase::InitSDL(SCRN_WIDTH, SCRN_HEIGHT);
	Game* game = new Game();
	game->Setup();
#ifndef RUN_TESTS
	game->Start();
#else
	Test_All ta;
	ta.Run_All_Tests();
	system("pause");
#endif //RUN_TESTS
	SAFE_DELETE_PTR(game);
	return 0;
}