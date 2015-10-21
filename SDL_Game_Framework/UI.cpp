#include "UI.h"

UI::UI() //default constructor
{
	set_flicker_sprite(flicker_sprite);
	flicker_sprite->set_visibility(true);
}

UI::~UI()
{
	//Appropriate memory clean up here
}

AW_Sprite_Interface* UI::get_flicker_sprite() const 
{
	return flicker_sprite;
}

void UI::set_flicker_sprite(AW_Sprite_Interface* flicker)
{
	flicker_sprite = flicker;
}

void UI::Flicker()
{

}
void UI::Display()
{
	
}