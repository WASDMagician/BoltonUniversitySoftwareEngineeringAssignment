#include "Text_Boxes.h"
#include "Game.h"


Text_Boxes::Text_Boxes()
	:m_p_font(NULL), m_messages(NULL), m_p_colour(new SDL_Color{ 255, 255, 255 }), m_p_background_colour(new SDL_Color{ 0, 0, 255 }),
	m_current_message(0), m_x_position(50), m_y_position(50), m_background_rect(NULL), m_should_flush(false)
{
}

//char* font_path, int pt_size, SDL_Color* text_colour, SDL_Color *background_colour, float x_pos, float y_pos, vector<string>messages
Text_Boxes::Text_Boxes(text_box_creation_variables *initialiser)
	:m_p_font(NULL), m_p_colour(initialiser->text_colour), m_p_background_colour(initialiser->background_colour),
	m_x_position(initialiser->x_position), m_y_position(initialiser->y_position), m_string_messages(initialiser->messages)
{
	set_font(initialiser->font_path, initialiser->pt_size);
	Setup_Message(m_string_messages);
}


Text_Boxes::~Text_Boxes()
{
	delete m_p_font;

}



void Text_Boxes::Setup_Message(std::vector<std::string> messages)
{
	for (int i = 0; i < messages.size(); i++)
	{
		SDL_Rect *nRect = new SDL_Rect;
		int width = 0;
		int height = 0;
		TTF_SizeText(get_font(), messages[i].c_str(), &width, &height);
		nRect->x = m_x_position;
		nRect->y = m_y_position + (i * (height + 10));
		if (width > m_width)
		{
			m_width = width;
		}
		m_height = nRect->y;
		text_box_message new_message{ new SDL_Surface(), messages[i], 0, 0, messages[i].size(), nRect};
		m_messages.push_back(new_message);
	}
	m_background_sprite = new AWSprite(m_width + 10, m_height - 10, 0, 0, 255);
	m_background_sprite->set_world_position(m_x_position - 10, m_y_position - 10);
}

SDL_Surface *Text_Boxes::get_surface_message()
{
	return m_messages[m_current_message].message_surface;
}

bool Text_Boxes::set_surface_message(std::string currentString)
{
	m_messages[m_current_message].message_surface = TTF_RenderText_Solid(get_font(), currentString.c_str(), *m_p_colour);
	return false;
}

TTF_Font *Text_Boxes::get_font()
{
	return m_p_font;
}

bool Text_Boxes::set_font(TTF_Font *font)
{
	m_p_font = font;
	return m_p_font == font;
}

bool Text_Boxes::set_font(char* fontPath, int ptSize)
{
	TTF_Font *font = TTF_OpenFont(fontPath, ptSize);
	m_p_font = font;
	return m_p_font == font;
}

SDL_Color *Text_Boxes::get_colour()
{
	return m_p_colour;
}

bool Text_Boxes::set_colour(SDL_Color *colour)
{
	m_p_colour = colour;
	return false;
}

bool Text_Boxes::set_should_flush(bool flush)
{
	m_should_flush = flush;
	return m_should_flush == flush;
}

bool Text_Boxes::get_should_flush()
{
	return m_should_flush;
}

bool Text_Boxes::flush_messages()
{
	if (m_should_flush)
	{
		if (m_messages[m_current_message].current_position < m_messages[m_current_message].end_position)
		{
			std::string curr_string = "";
			for (int i = m_messages[m_current_message].start_position; i <= m_messages[m_current_message].current_position; i++)
			{
				curr_string += m_messages[m_current_message].message[i];
			}
			set_surface_message(curr_string);
			if (m_messages[m_current_message].current_position < m_messages[m_current_message].end_position)
			{
				m_messages[m_current_message].current_position++;
			}
		}
		else
		{
			if (m_current_message < m_messages.size())
			{
				m_current_message++;
			}
		}
	}
	else
	{
		for (int i = 0; i < m_messages.size(); i++)
		{
			set_surface_message(m_messages[i].message);
			m_current_message++;
		}
	}
	return false;
}

void Text_Boxes::Update()
{
	if (m_current_message <= m_messages.size() - 1)
	{
		flush_messages();
	}
}

void Text_Boxes::Render_Text()
{
	m_background_sprite->update_everything();
	for (int i = 0; i < m_messages.size(); i++)
	{
		SDL_BlitSurface(m_messages[i].message_surface, NULL, SDL_GetVideoSurface(), m_messages[i].rect);	
	}
}