#include "Test_Text_Box.h"


Test_Text_Box::Test_Text_Box(char* fontPath, int fontSize, std::string message)
	:Text_Box(fontPath, fontSize, message)
{
}


Test_Text_Box::~Test_Text_Box()
{
}


TTF_Font* Test_Text_Box::get_font()
{
	return m_font;
}

int Test_Text_Box::get_font_size()
{
	return m_font_size;
}

SDL_Color Test_Text_Box::get_font_color()
{
	return m_font_color;
}

std::vector<SDL_Surface*> Test_Text_Box::get_text_lines()
{
	return m_text_lines;
}

std::vector<SDL_Rect*> Test_Text_Box::get_text_rects()
{
	return m_text_rects;
}
std::vector<std::string> Test_Text_Box::get_messages()
{
	return m_messages;
}

AWSprite* Test_Text_Box::get_box()
{
	return m_box;
}

//display
bool Test_Text_Box::get_should_display()
{
	return m_should_display;
}

float Test_Text_Box::get_box_x()
{
	return m_box_x;
}

float Test_Text_Box::get_box_y()
{
	return m_box_y;
}

int Test_Text_Box::get_line_height()
{
	return m_line_height;
}

float Test_Text_Box::get_max_line_width()
{
	return m_max_line_width;
}

int Test_Text_Box::get_number_of_lines()
{
	return m_number_of_lines;
}

float Test_Text_Box::get_total_text_height()
{
	return m_total_text_height;
}

int Test_Text_Box::get_current_line()
{
	return m_current_line;
}
