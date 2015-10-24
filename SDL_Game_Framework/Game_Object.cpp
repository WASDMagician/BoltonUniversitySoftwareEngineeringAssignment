#include "Game_Object.h"
#include "Game.h"


Game_Object::Game_Object()
:sprite(new AWSprite()), transform(new Transform())
{
	set_transform();
}

Game_Object::Game_Object(game_object_constructor_variables *initialiser)
: sprite(new AWSprite(initialiser->img_path, (int)initialiser->rows, (int)initialiser->cols)), transform(new Transform()), game_screen(initialiser->game_screen)
{
	set_transform();
}


Game_Object::~Game_Object()
{
}

bool Game_Object::set_sprite(char* img, int cols, int rows)
{
	sprite = new AWSprite(img, cols, rows);
	
	return true;
}

bool Game_Object::set_transform(void)
{
	transform->m_p_gameobject = this;
	return true;
}

bool Game_Object::serialize_game_object()
{
	return false;
}