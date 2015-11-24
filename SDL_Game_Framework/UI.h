#ifndef _UI_H_
#define _UI_H_

#include <string>
#include <iostream>
#include "Game_Constants.h"
#include "AWSprite.h"
#include "Text_Box.h"
#include "Character.h"
#include "GameBase.h"

class UI
{
public:
	UI();
	virtual ~UI();
	virtual void Display(); // i know Joe likes his bools rather than void	

protected:
	AW_Sprite_Interface* sprite;
};
#endif