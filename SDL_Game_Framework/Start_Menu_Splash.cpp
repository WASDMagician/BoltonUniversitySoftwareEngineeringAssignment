#include "Start_Menu_Splash.h"
#include "Game.h"

Start_Menu_Splash::Start_Menu_Splash(Game *game)
: Splash_Screen(game), m_instruction_box(NULL)
{
	m_instruction_box = new Text_Box(); //initialise instruction box
}

Start_Menu_Splash::~Start_Menu_Splash(void)
{
	//free menu
	delete m_instruction_box;
	m_instruction_box = NULL;
}

void Start_Menu_Splash::Setup()
{
	//setup instruction box
	m_instruction_box->set_font("fonts/game_font.ttf", 20);
	m_instruction_box->set_color(200, 0, 0);
	m_instruction_box->Position_Setting(50, 50, 10, 10);
	m_instruction_box->Add_Message("Welcome to our game\nUse WASD to move\nCollect all the coins to reveal \nthe exits\nWin the game");
	m_instruction_box->Setup_Box();
	m_instruction_box->set_rects();
}

void Start_Menu_Splash:: Handle_Keys()
{
	switch (m_game->keyUp) //use a switch statement to deal with multiple single keypresses
	{
	case(SDLK_RETURN) :
		m_close_splash = true; //splash will close causing the next screen to run
		break;
	case(SDLK_ESCAPE) :
		m_game_over = true;
		m_close_splash = true;
		break;
	default:
		break;
	}	
}


void Start_Menu_Splash:: Render_Back()
{
	SDL_BlitSurface(m_game->bg, NULL, m_game->screen, NULL); //render black background to prevent screen smearing
}

void Start_Menu_Splash:: Render_Mid()
{
	m_instruction_box->Display(); //rendir instruction box
}


bool Start_Menu_Splash::Run()
{
	Start(); //start the splash loop
	return is_game_over(); //return whether the game should quit or not
}