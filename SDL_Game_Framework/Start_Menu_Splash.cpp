#include "Start_Menu_Splash.h"
#include "Game.h"



Start_Menu_Splash::Start_Menu_Splash()
:Splash_Screen(NULL, NULL, "Start_Menu_Splash"), instruction_box(NULL)
{
	instruction_box = new Text_Box();
}

Start_Menu_Splash::Start_Menu_Splash(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg, "Start_Menu_Splash"), instruction_box(NULL)
{
	instruction_box = new Text_Box();
	m_p_game->SetBackground(bgImg);
}

Start_Menu_Splash::~Start_Menu_Splash(void)
{
	delete instruction_box;
	instruction_box = NULL;
}

void Start_Menu_Splash::Setup()
{
	instruction_box->set_font("fonts/game_font.ttf", 20);
	instruction_box->set_color(200, 0, 0);
	instruction_box->Position_Setting(50, 50, 10, 10);
	instruction_box->Add_Message("Welcome to our game\nPress Enter to start\nFind the exits\nWin the game");
	instruction_box->Setup_Box();
	instruction_box->set_rects();
	instruction_box->set_should_display(true);
}

void Start_Menu_Splash:: Handle_Keys()
{
	switch (m_p_game->keyUp)
	{
	case(SDLK_RETURN) :
		m_b_close_splash = true;
		break;
	}
}

void Start_Menu_Splash::Logic()
{

}

void Start_Menu_Splash:: Render_Back()
{
	SDL_BlitSurface(m_p_game->bg, NULL, m_p_game->screen, NULL);
}

void Start_Menu_Splash:: Render_Mid()
{
	
	instruction_box->Display();
}

void Start_Menu_Splash:: Render_Front()
{
}


bool Start_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}