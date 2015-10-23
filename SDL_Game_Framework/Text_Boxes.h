#ifndef _TEXT_BOXES_H_
#define _TEXT_BOXES_H_

#include <string>
#include <vector>

#include "Game_Object.h"
#include "SDL_ttf.h"
class Game;

struct text_box_message
{
	SDL_Surface *message_surface;
	std::string message;
	int start_position;
	int current_position;
	int end_position;

	SDL_Rect *rect;
};

class Text_Boxes:
	public Game_Object
{
public:
	Text_Boxes();
	~Text_Boxes();
	void Setup_Message(std::vector<std::string> messages);

	SDL_Surface *get_surface_message();
	bool set_surface_message(std::string);

	Game *get_game();
	bool set_game(Game *game);

	TTF_Font *get_font();
	bool set_font(TTF_Font *font);

	SDL_Color *get_colour();
	bool set_colour(SDL_Color *colour);

	bool set_should_flush(bool flush);
	bool get_should_flush();

	bool flush_messages();

	void Update();

	void Render_Text();

private:
	Game *m_p_game;
	TTF_Font *m_p_font;
	SDL_Color *m_p_colour;
	SDL_Color *m_p_background_colour;

	std::vector<text_box_message>m_messages;

	int m_current_message;

	int m_x_position;
	int m_y_position;

	SDL_Surface *m_background_surface;
	SDL_Rect *m_background_rect;

	int m_width;
	int m_height;

	bool m_should_flush;
	
};

#endif //_TEXT_BOXE_H_