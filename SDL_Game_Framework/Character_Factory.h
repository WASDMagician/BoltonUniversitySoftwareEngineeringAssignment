#ifndef _CHARACTER_FACTORY_H_
#define _CHARACTER_FACTORY_H_

class Character;

class Character_Factory
{
public:
	virtual Character* Make_Character(int character_type) = 0;
};

#endif //_CHARACTER_FACTORY_H_