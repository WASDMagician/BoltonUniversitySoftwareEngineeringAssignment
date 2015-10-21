#ifndef _UI_H_
#define _UI_H_

#include <string>
#include <iostream>
#include "Game_Object.h"
#include "Game_Constants.h"

class UI : 
	public Game_Object
{
public:
	UI();
	virtual ~UI();
	virtual void Display(); // i know Joe likes his bools rather than void	
};
#endif