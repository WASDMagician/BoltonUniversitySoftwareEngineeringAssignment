#include "Game.h"
#include "SDL_ttf.h"
#include "Game_Constants.h"
#include "Test_All.h"
#include <iostream>



int main(int argc, char *argv[])
{
	GameBase::InitSDL(SCRN_WIDTH, SCRN_HEIGHT);	
	TTF_Init(); //initialise SDL_TTF library (third party library to deal with fonts and displaying text)
#ifndef RUN_TESTS
	Game* game = new Game();
	game->Setup();
	game->Start();
	SAFE_DELETE_PTR(game);
#else
	Test_All ta;
	ta.Run_All_Tests();
#endif //RUN_TESTS
	return 0;
}