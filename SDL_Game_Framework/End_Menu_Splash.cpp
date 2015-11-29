#include "End_Menu_Splash.h"
#include "Game.h"

End_Menu_Splash::End_Menu_Splash()
:Splash_Screen(NULL), m_gameover_box(NULL)
{
	m_gameover_box = new Text_Box();
}

End_Menu_Splash::End_Menu_Splash(Game *pGame)
: Splash_Screen(pGame), m_gameover_box(NULL)
{
	m_gameover_box = new Text_Box();
}

End_Menu_Splash::~End_Menu_Splash(void)
{

}

void End_Menu_Splash::Setup()
{
	m_gameover_box->set_font("fonts/game_font.ttf", 20);
	m_gameover_box->set_color(200, 0, 0);
	m_gameover_box->Position_Setting(50, 50, 10, 10);
	m_gameover_box->Add_Message("Thank you for playing our game\nPress Escape to exit");
	m_gameover_box->Setup_Box();
	m_gameover_box->set_rects();
	m_gameover_box->set_should_display(true);
}

void End_Menu_Splash::Handle_Keys()
{
	switch (m_game->keyDown)
	{
	case(SDLK_ESCAPE) :
		m_game_over = true;
		m_close_splash = true;
		break;
	}
}


void End_Menu_Splash::Render_Back()
{
	SDL_BlitSurface(m_game->bg, NULL, m_game->screen, NULL);
}

void End_Menu_Splash::Render_Mid()
{
	m_gameover_box->Display();
}

bool End_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}