#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "AW_Sprite_Interface.h"

class Object :
	public AW_Sprite_Interface
{
public:
	Object();
	Object(std::string name);
	~Object();

	bool set_obtained(bool obtained);
	bool get_obtained(); // dont know if we need this but whatever...
	bool set_glowing(bool glowing);
	bool get_glowing(); // to help you locate items

private:
	std::string m_name; // in case we have multiple items that want names?

	bool m_is_obtained; // something to toggle for when player collides with it
	bool m_is_glowing; // glowing for unobtained, stop glowing then dissappear when collided into perhaps?
};
#endif