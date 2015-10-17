#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Game_Object.h"

class Object :
	public Game_Object
{
public:
	Object();
	Object(float x, float y, std::string name);
	~Object();

	bool IsObtained(); // dont know if we need this but whatever...
	bool IsGlowing(); // to help you locate items

private:
	float m_xPos; // position in game (X)
	float m_yPos; // position in game (Y)
	std::string m_name; // in case we have multiple items that want names?

	bool m_is_obtained; // something to toggle for when player collides with it
	bool m_is_glowing; // glowing for unobtained, stop glowing then dissappear when collided into perhaps?
};
#endif