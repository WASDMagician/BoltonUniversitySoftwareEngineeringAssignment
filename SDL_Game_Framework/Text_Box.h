#ifndef _TEXT_BOX_H_
#define _TEXT_BOX_H_

#include "AWSprite.h"
#include "SDL_ttf.h"
#include <vector>

class Game;

class Text_Box:
	AWSprite
{
public:
	Text_Box();
	Text_Box(char* fontPath, int fontSize, std::string message);
	~Text_Box();

	void set_font(char* fontPath, int fontSize);
	void set_color(int r, int g, int b);

	void Position_Setting(bool boxShouldBeDrawn, float boxX, float boxY, float textXMargin, float textYMargin);
	void set_box_color(int r, int g, int b);

	void Setup_Box();
	void set_rects();

	void Add_Message(std::string message); //add a new line to the text box

	std::string get_message(unsigned int index); //get string of message at index
	std::vector<std::string>get_messages(); //get a vector of all lines in text box

	void Display(); //display text box

private:
	//setup
	TTF_Font *m_font;
	int m_font_size;
	SDL_Color m_font_color;

	void Parse_Text(std::string message); //split text up at \n
	SDL_Surface *Create_Text_Line(std::string message); //create an sdl surface for each line of text
	

	std::vector<SDL_Surface*>m_text_lines; //holds all rendered text
	std::vector<SDL_Rect*>m_text_rects; //holds rects for all text
	std::vector<std::string>m_messages; //holds all text lines

	AWSprite *m_box; //sits behind text
	SDL_Color m_box_color; //colour of the box

	//display
	bool m_box_should_be_drawn;
	float m_box_x; //left of box
	float m_box_y; //top of box
	float m_text_x_margin; //distance between left of box and start of line, right of box and end of line
	float m_text_y_margin; //distance between top of box and first line, bottom of box and last line

	int m_line_height; //character height
	int m_max_line_width; //widest line of text
	float m_number_of_lines;
	float m_total_text_height; //current y position of lowest text
	int m_current_line; //current line we are rendering
};

#endif //_TEXT_BOX_H_