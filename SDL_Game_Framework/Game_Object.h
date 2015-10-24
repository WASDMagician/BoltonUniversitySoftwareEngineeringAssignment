#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "Transform.h"
#include "AWSprite.h"

class Game;

struct game_object_constructor_variables
{
	char* img_path;
	unsigned int cols;
	unsigned int rows;
	SDL_Surface* game_screen;
};

class Game_Object
{
public:
	Game_Object();
	Game_Object(game_object_constructor_variables *initialiser);
	~Game_Object();
	
	Transform* transform;
	bool set_transform(void);
	bool set_sprite(char* img, int cols, int rows);

	virtual bool serialize_game_object();

	AWSprite *sprite;

	SDL_Surface *game_screen;
private:
	
};
#endif //_GAME_OBJECT_H_

