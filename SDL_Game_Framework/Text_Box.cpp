#include "Text_Box.h"
#include "Game.h"

Text_Box::Text_Box()
	:m_font(NULL), m_text_lines(NULL), m_messages(NULL), m_box(NULL), m_box_should_be_drawn(false), m_box_color({ 0, 0, 0 }), m_box_x(0), m_box_y(0), m_text_x_margin(0), m_text_y_margin(0),
	m_current_line(0), m_total_text_height(0), m_number_of_lines(0), m_line_height(0), m_font_color({ 0, 0, 0 }), m_text_rects(NULL),
	m_b_should_display(false)
{
}


Text_Box::Text_Box(char* fontPath, int fontSize, std::string message)
	:m_font(NULL), m_text_lines(NULL), m_messages(NULL), m_box(NULL), m_box_should_be_drawn(false), m_box_color({ 0, 0, 0 }), m_box_x(0), m_box_y(0), m_text_x_margin(0), m_text_y_margin(0),
	m_current_line(0), m_total_text_height(0), m_number_of_lines(0), m_line_height(0), m_font_color({ 0, 0, 0 }), m_text_rects(NULL),
	m_b_should_display(false)
{
	set_font(fontPath, fontSize);
	Add_Message(message);
}


Text_Box::~Text_Box()
{
}



void Text_Box::set_font(char* fontPath, int fontSize)
{
	delete m_font;
	m_font = TTF_OpenFont(fontPath, fontSize);
	TTF_SizeText(m_font, "A", NULL, &m_line_height); //get the height of the text (A chosen randomly)
}

void Text_Box::set_color(int r, int g, int b)
{
	m_font_color.r = r;
	m_font_color.g = g;
	m_font_color.b = b;
}

void Text_Box::Position_Setting(bool boxShouldBeDrawn, float boxX = 0, float boxY = 0, float textXMargin = 0, float textYMargin = 0)
{
	
	m_box_should_be_drawn = boxShouldBeDrawn;
	m_box_x = boxX;
	m_box_y = boxY;
	m_text_x_margin = textXMargin;
	m_text_y_margin = textYMargin;
}

void Text_Box::Setup_Box()
{
	m_box = new AWSprite();
	if (m_max_line_width > 0) //check that m_max_line_width has been set correctly
	{
		
		m_box->setImage(m_max_line_width + (int)(m_text_x_margin * 2), (int)((m_line_height * m_number_of_lines) + (int)m_text_y_margin * 2), m_box_color.r, m_box_color.g, m_box_color.b);
		m_box->set_world_position(m_box_x, m_box_y);
	}
}

void Text_Box::set_rects()
{
	for (unsigned int i = 0; i < m_text_rects.size(); i++)
	{
		if (m_text_rects[i] != NULL)
		{
			delete m_text_rects[i];
			m_text_rects[i] = NULL;
		}
	}
	m_text_rects.clear();

	for (unsigned int i = 0; i < m_text_lines.size(); i++)
	{
		SDL_Rect *new_rect= new SDL_Rect();
		int width = 0;
		int height = 0;
		TTF_SizeText(m_font, m_messages[i].c_str(), &width, &height);
		new_rect->w = width;
		new_rect->h = height;
		new_rect->x = (Sint16)m_box_x + (Sint16)m_text_x_margin;
		new_rect->y = (Sint16)m_box_y + (Sint16)((i * m_line_height) + (Sint16)m_text_y_margin);
		m_text_rects.push_back(new_rect);
	}
}

void Text_Box::set_box_color(int r, int g, int b)
{
	m_box_color.r = r;
	m_box_color.g = g;
	m_box_color.b = b;
}

void Text_Box::Add_Message(std::string message)
{
	Parse_Text(message);
	for (auto &c : m_messages)
	{
		m_text_lines.push_back(Create_Text_Line(c));
	}
}

std::string Text_Box::get_message(unsigned int i)
{
	return (i < m_messages.size()) ? (m_messages[i]) : ("!!Index out of range, that messages does not exist!!");
}

std::vector<std::string> Text_Box::get_messages()
{
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
	SDL_Surface *text_line = TTF_RenderText_Blended(m_font, message.c_str(), m_font_color);
	int height = 0;
	int width = 0;
	TTF_SizeText(m_font, message.c_str(), &width, &height);
	m_max_line_width = (width > m_max_line_width) ? (width) : (m_max_line_width); //if width > current max width then max width = width, else stays the same

	return text_line;
}

void Text_Box::set_should_display(bool display)
{
	m_b_should_display = display;
}

bool Text_Box::get_should_display()
{
	return m_b_should_display;
}

void Text_Box::Display()
{
	if (m_box_should_be_drawn)
	{
		m_box->update_everything();
	}
	for (unsigned int i = 0; i < m_text_lines.size(); i++)
	{
		SDL_BlitSurface(m_text_lines[i], NULL, SDL_GetVideoSurface(), m_text_rects[i]);
	}
	
}