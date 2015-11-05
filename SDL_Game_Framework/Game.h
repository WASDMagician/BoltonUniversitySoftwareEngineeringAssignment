#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "UI_Play_Screen.h"
#include "NPC_Shopkeeper.h"
#include "NPC_Hinter.h"
#include "SDL_ttf.h"
#include "Text_Box.h"
#include "Inventory.h"
#include "Start_Menu_Splash.h"
#include "Play_Screen.h"
#include "End_Menu_Splash.h"
#include "Pause_Menu_Splash.h"
#include "Character.h"
#include "Weapon.h"
#include "Projectile.h"


class Game :
	public GameBase
{
public:
	Game();
	~Game();

	void Setup();
	void Run();

private:
	Splash_Screen *splash;

	Projectile *projectile;

	std::vector<Projectile> proj_array;
};
#endif // _GAME_H_

