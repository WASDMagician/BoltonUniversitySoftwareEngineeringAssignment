#pragma once
#include "GameBase.h"

#include "Player.h"

class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Logic();
	void Draw();

	Player *new_player;
	
};

