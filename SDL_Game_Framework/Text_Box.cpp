#include "Text_Box.h"
#include "Game.h"

Text_Box::Text_Box()
	:m_font(NULL), m_text_lines(NULL), m_messages(NULL), m_box(NULL), m_box_x(0), m_box_y(0), m_text_x_margin(0), m_text_y_margin(0),
	m_current_line(0), m_total_text_height(0), m_number_of_lines(0), m_line_height(0), m_font_color({ 0, 0, 0 }), m_text_rects(NULL),
	m_should_display(false)
{
}


Text_Box::Text_Box(char* fontPath, int fontSize, std::string message)
	:m_font(NULL), m_text_lines(NULL), m_messages(NULL), m_box(NULL), m_box_x(0), m_box_y(0), m_text_x_margin(0), m_text_y_margin(0),
	m_current_line(0), m_total_text_height(0), m_number_of_lines(0), m_line_height(0), m_font_color({ 0, 0, 0 }), m_text_rects(NULL),
	m_should_display(false)
{
	set_font(fontPath, fontSize);
	Add_Message(message);
}


Text_Box::~Text_Box()
{
	//free memory
	if (m_font != NULL)
	{
		TTF_CloseFont(m_font);
	}

	for (size_t i = 0; i < m_text_lines.size(); i++)
	{
		SDL_FreeSurface(m_text_lines[i]);
		m_text_lines[i] = NULL;
	}
	m_text_lines.clear();
	
	for (size_t i = 0; i < m_text_rects.size(); i++)
	{
		delete m_text_rects[i];
		m_text_rects[i] = NULL;
	}
	m_text_rects.clear();

	if (m_box != NULL)
	{
		delete m_box;
	}
}


void Text_Box::set_font(char* fontPath, int fontSize)
{	
	TTF_CloseFont(m_font);
	delete m_font;
	m_font = NULL;

	m_font = TTF_OpenFont(fontPath, fontSize);
	TTF_SizeText(m_font, "A", NULL, &m_line_height); //get the height of the text (A chosen randomly)
}

void Text_Box::set_color(int r, int g, int b)
{
	m_font_color.r = r;
	m_font_color.g = g;
	m_font_color.b = b;
}

void Text_Box::Position_Setting(float boxX = 0, float boxY = 0, float textXMargin = 0, float textYMargin = 0)
{
	//set the position of the invisible awsprite box, this will be used for positioning
	m_box_x = boxX;
	m_box_y = boxY;
	//add any x and y margin wanted for the actual text (left-over code, not strictly necesarry)
	m_text_x_margin = textXMargin;
	m_text_y_margin = textYMargin;
}

void Text_Box::Setup_Box()
{
	delete m_box;
	m_box = NULL;
	m_box = new AWSprite(); //create inivisible awsprite box for positioning
	if (m_max_line_width > 0) //if there are lines of text
	{
		m_box->set_world_position(m_box_x, m_box_y); //set box position
	}
}

void Text_Box::set_rects()
{
	for (size_t i = 0; i < m_text_rects.size(); i++) //clear current text rects
	{
		if (m_text_rects[i] != NULL)
		{
			delete m_text_rects[i];
			m_text_rects[i] = NULL;
		}
	}
	m_text_rects.clear();

	for (size_t i = 0; i < m_text_lines.size(); i++) //add new text rects
	{
		SDL_Rect *new_rect= new SDL_Rect(); //create text rects
		int width = 0; //initialise width
		int height = 0; //initialise height
		TTF_SizeText(m_font, m_messages[i].c_str(), &width, &height); //get size of string
		new_rect->w = width; //set rect width
		new_rect->h = height; //set rect height
		new_rect->x = (Sint16)m_box_x + (Sint16)m_text_x_margin; //rect position is box position + margin
		new_rect->y = (Sint16)m_box_y + (Sint16)((i * m_line_height) + (Sint16)m_text_y_margin);
		m_text_rects.push_back(new_rect);
	}
}

void Text_Box::Add_Message(std::string message)
{
	Parse_Text(message); //split given string into lines using "\n" as the delimiter.
	for (size_t i = 0; i < m_text_lines.size(); i++) //iterate over created lines
	{
		SDL_FreeSurface(m_text_lines[i]); //free up any previsouly used memory
		delete m_text_lines[i];
		m_text_lines[i] = NULL;
	}
	for (size_t m = 0; m < m_messages.size(); m++)
	{
		m_text_lines.push_back(Create_Text_Line(m_messages[m])); //push back current lines
	}
}

std::string Text_Box::get_message(int i)
{
	//if m_message[i] exists then return that message, otherwise return error
	return (i < m_messages.size()) ? (m_messages[i]) : ("!!Index out of range, that messages does not exist!!");
}

std::vector<std::string> Text_Box::get_messages()
{
	//return all messages
	return m_messages;
}

void Text_Box::Parse_Text(std::string message)
{
	size_t pos = 0;
	std::string delim = "\n"; //used to get line breaks
	while ((pos = message.find(delim)) != std::string::npos) //while pos is not the end of the line
	{
		std::string line = message.substr(0, message.find(delim)); //get the part we want
		m_messages.push_back(line); //add to messages
		message.erase(0, message.find(delim) + delim.length()); //remove the part we have found including teh delimiter
		m_number_of_lines++; //increment number of lines
	}
	if (message.find_first_not_of(' ') != std::string::npos) //check that remaining message is not only spaces
	{
		m_messages.push_back(message); //once the end is found push the remaining part of the message
		m_number_of_lines++; //increment number of lines
	}
}

SDL_Surface* Text_Box::Create_Text_Line(std::string message)
{
	SDL_Surface *text_line = TTF_RenderText_Blended(m_font, message.c_str(), m_font_color); //create new sdl surface with rendered text
	int height = 0; //initialise height
	int width = 0;  //initialise width
	TTF_SizeText(m_font, message.c_str(), &width, &height); //get size of line
	m_max_line_width = (width > m_max_line_width) ? (width) : (m_max_line_width); //if width > current max width then max width = width, else stays the same
	return text_line;
}

void Text_Box::set_should_display(bool display)
{
	m_should_display = display;
}

bool Text_Box::get_should_display()
{
	return m_should_display;
}

void Text_Box::Display()
{
	for (unsigned int i = 0; i < m_text_lines.size(); i++)
	{
		SDL_BlitSurface(m_text_lines[i], NULL, SDL_GetVideoSurface(), m_text_rects[i]);
	}
	
}