#pragma once
#include "Text_Box.h"
class Test_Text_Box :
	public Text_Box
{
public:
	Test_Text_Box(char* fontPath, int fontSize, std::string message);
	~Test_Text_Box();

	TTF_Font* get_font();
	int get_font_size();
	SDL_Color get_font_color();

	std::vector<SDL_Surface*> get_text_lines(); //holds all rendered text
	std::vector<SDL_Rect*> get_text_rects(); //holds rects for all text
	std::vector<std::string> get_messages(); //holds all text lines

	AWSprite* get_box(); //this is not displayed, it is used for positioning purposes only

	//display
	bool get_should_display();

	float get_box_x(); //left of box
	float get_box_y(); //top of box

	int get_line_height(); //character height cannot be float due to TTF_SizeText requirements
	float get_max_line_width(); //widest line of text
	int get_number_of_lines();
	float get_total_text_height(); //current y position of lowest text
	int get_current_line(); //current line we are rendering
};

