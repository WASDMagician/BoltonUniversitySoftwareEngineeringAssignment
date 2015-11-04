#ifndef _NPC_BASE_H_
#define _NPC_BASE_H_

#include "AW_Sprite_Interface.h"
#include <string>

class NPC_Base : 
	public AW_Sprite_Interface
{
public:
	//char* img_path, unsigned int rows, unsigned int cols, string name, unsigned int health, unsigned int damage, unsigned int defence, unsigned animation_speed
	NPC_Base();
	virtual ~NPC_Base();

	virtual bool set_name(std::string name);
	std::string get_name();

protected:
	std::string m_name;
};

#endif //_NPC_BASE_H_