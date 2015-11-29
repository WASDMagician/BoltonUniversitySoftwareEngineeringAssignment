#include "Start_Menu_Splash.h"
#include "Game.h"

Start_Menu_Splash::Start_Menu_Splash()
:Splash_Screen(NULL), m_instruction_box(NULL)
{
	m_instruction_box = new Text_Box();
}

Start_Menu_Splash::Start_Menu_Splash(Game *game)
: Splash_Screen(game), m_instruction_box(NULL)
{
	m_instruction_box = new Text_Box();
}

Start_Menu_Splash::~Start_Menu_Splash(void)
{
	delete m_instruction_box;
	m_instruction_box = NULL;
}

void Start_Menu_Splash::Setup()
{
	m_instruction_box->set_font("fonts/game_font.ttf", 20);
	m_instruction_box->set_color(200, 0, 0);
	m_instruction_box->Position_Setting(50, 50, 10, 10);
	m_instruction_box->Add_Message("Welcome to our game\nPress Enter to start\nFind the exits\nWin the game");
	m_instruction_box->Setup_Box();
	m_instruction_box->set_rects();
	m_instruction_box->set_should_display(true);
}

void Start_Menu_Splash:: Handle_Keys()
{
	switch (m_game->keyUp)
	{
	case(SDLK_RETURN) :
		m_close_splash = true;
		break;
	}
}


void Start_Menu_Splash:: Render_Back()
{
	SDL_BlitSurface(m_game->bg, NULL, m_game->screen, NULL);
}

void Start_Menu_Splash:: Render_Mid()
{
	m_instruction_box->Display();
}


bool Start_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}