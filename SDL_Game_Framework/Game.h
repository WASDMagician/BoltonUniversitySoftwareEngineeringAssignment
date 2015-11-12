#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "SDL_ttf.h"
#include "Text_Box.h"
#include "Splash_Screen.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Run();
	void Draw();

private:
	Splash_Screen *splash;
	Text_Box *credit_box;
};
#endif // _GAME_H_

