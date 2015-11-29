#ifndef _UI_PLAY_SCREEN_H_	
#define _UI_PLAY_SCREEN_H_

#include <string>
#include <iostream>
#include "Game_Constants.h"
#include "AW_Sprite_Interface.h"
#include "GameBase.h"

#include "Character.h"
#include "Text_Box.h"

class UI_Play_Screen
{
public:
	UI_Play_Screen();
	UI_Play_Screen(Character* character);
	~UI_Play_Screen();

	void set_character(Character* character);
	
	void Update();

	void Display();
	

private:
	Character *m_display_character; //the character who's details we will display
	Text_Box *m_ui_details; //the text box on which we will display them

};

#endif // End of _UI_PLAY_SCREEN_H_
