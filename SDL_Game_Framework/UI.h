#ifndef _UI_H_
#define _UI_H_

#include <string>
#include <iostream>
#include "AW_Sprite_Interface.h"

class UI : AW_Sprite_Interface
{
public:
	UI();
	virtual ~UI();
	virtual void Display(); // i know Joe likes his bools rather than void	

	virtual void Flicker();

	AW_Sprite_Interface* get_flicker_sprite() const;
	virtual void set_flicker_sprite(AW_Sprite_Interface* flicker);

private:
	AW_Sprite_Interface* flicker_sprite;
};
#endif