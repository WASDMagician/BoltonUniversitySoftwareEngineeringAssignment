#include "Start_Menu_Splash.h"
#include "Game.h"



Start_Menu_Splash::Start_Menu_Splash()
	:Splash_Screen(NULL, NULL, "Start_Menu_Splash")
{

}

Start_Menu_Splash::Start_Menu_Splash(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg, "Start_Menu_Splash")
{
	m_p_game->SetBackground(bgImg);
}

Start_Menu_Splash::~Start_Menu_Splash(void)
{

}

void Start_Menu_Splash::Setup()
{
	tb.set_font("fonts/game_font.ttf", 28);
	tb.set_color(200, 0, 0);
	tb.set_box_color(255, 255, 255);
	tb.Position_Setting(true, 50, 50, 10, 10);
	tb.Add_Message("This is a test\nAnother test\nYet Another Test\n testing testing\nkEEP Adding stuff\nhow far will it go\ntrolololollol");
	tb.Setup_Box();
	tb.set_rects();
}

void Start_Menu_Splash:: Handle_Keys()
{
	switch (m_p_game->keyUp)
	{
	case(SDLK_SPACE):
		printf("Start");
		break;
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
	
	tb.Display();
}

void Start_Menu_Splash:: Render_Front()
{
}


bool Start_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}