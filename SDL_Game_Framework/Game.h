#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"

#include "Player.h"
#include "UI.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Logic();
	void Draw();
	void User_Interface();

	Player *new_player;
	UI *new_ui;
	
};
#endif // _GAME_H_

