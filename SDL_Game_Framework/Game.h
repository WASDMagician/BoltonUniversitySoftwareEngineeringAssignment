#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "SDL_ttf.h"
#include "Text_Box.h"

#include "Splash_Screen.h"
#include "Start_Menu_Splash.h"
#include "Play_Screen.h"
#include "End_Menu_Splash.h"

#include "Game_Time.h"

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
	Splash_Screen *m_splash;
	Text_Box *m_credit_box;
	
};
#endif // _GAME_H_

