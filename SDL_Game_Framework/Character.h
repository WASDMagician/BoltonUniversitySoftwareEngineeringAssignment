#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

#include "AWSprite.h"
#include "Transform.h"

class Character : public AWSprite
{
public:
	Character();
	Character(char *img, int rows, int cols, Transform trans, std::string name);
	~Character();

	std::string get_character_name();

	//not sure how useful transform type is going to be, will need to interact with AWSprite
	Transform character_transform;
	Transform weapon_offset;
	Transform object_offset;

private:
	std::string m_name;
};

#endif
