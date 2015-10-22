#include "Game_Object.h"


Game_Object::Game_Object()
:sprite(new AWSprite()), transform(new Transform())
{
	set_transform();
}

Game_Object::Game_Object(char* img, int cols, int rows)
:sprite(new AWSprite()), transform(new Transform())
{
	set_transform();
	set_sprite(img, cols, rows);
}


Game_Object::~Game_Object()
{
}

bool Game_Object::set_sprite(char* img, int cols, int rows)
{
	sprite = new AWSprite(img, cols, rows);
	
	return true;
}

bool Game_Object::set_transform()
{
	transform->m_p_gameobject = this;
	return true;
}

bool Game_Object::serialize_game_object()
{
	return false;
}