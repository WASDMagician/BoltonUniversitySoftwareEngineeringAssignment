#ifndef _GAME_H_
#define _GAME_H_

#include "GameBase.h"
#include "UI_Play_Screen.h"
#include "NPC_Shopkeeper.h"
#include "NPC_Hinter.h"
#include "SDL_ttf.h"
#include "Text_Boxes.h"
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
//	Text_Boxes *splash_box;
	void Logic();
	void Logic_Start();
	void Logic_Play();
	void Logic_Pause();
	void Logic_End();

	void OnKeyPressed();

	void Handle_Play_Keys();
	void Handle_Projectile();

	void Draw();
	void Draw_Play();

	void RenderHUD();

private:

	Text_Boxes *splash_box;
	Splash_Screen *splash;
	Inventory *inventory;
	Character *ogre;
	Character *jesus;
	Character *player;
	Weapon *crossbow;
	Weapon *great_axe;
	Weapon *sniper;
	Player *player;
	Enemy *ogre;

	Projectile *projectile;

	std::vector<Projectile> proj_array;

	NPC_Hinter *clown;
};
#endif // _GAME_H_

