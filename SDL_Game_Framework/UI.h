#ifndef _UI_H_
#define _UI_H_

#include <string>
#include <iostream>
#include "AW_Sprite_Interface.h"

class UI
{
public:
	UI();
	virtual ~UI();
	virtual void Display(); // i know Joe likes his bools rather than void	
};
#endif