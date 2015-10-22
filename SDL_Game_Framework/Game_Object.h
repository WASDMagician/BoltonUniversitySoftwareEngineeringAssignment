#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "Transform.h"
#include "AW_Sprite_Interface.h"

class Game_Object
{
public:
	Game_Object();
	Game_Object(char* img, int cols, int rows);
	~Game_Object();
	
	Transform* transform;
	bool set_transform();
	bool set_sprite(char* img, int cols, int rows);

	virtual bool serialize_game_object();

	AW_Sprite_Interface *sprite;
private:
	
};
#endif //_GAME_OBJECT_H_

