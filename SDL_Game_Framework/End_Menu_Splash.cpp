#include "End_Menu_Splash.h"
#include "Game.h"

End_Menu_Splash::End_Menu_Splash()
:Splash_Screen(NULL, NULL, "End_Menu_Splash"), gameover_box(NULL)
{
	gameover_box = new Text_Box();
}

End_Menu_Splash::End_Menu_Splash(Game *pGame, char* bgImg)
: Splash_Screen(pGame, bgImg, "End_Menu_Splash"), gameover_box(NULL)
{
	gameover_box = new Text_Box();
}

End_Menu_Splash::~End_Menu_Splash(void)
{

}

void End_Menu_Splash::Setup()
{
	gameover_box->set_font("fonts/game_font.ttf", 20);
	gameover_box->set_color(200, 0, 0);
	gameover_box->Position_Setting(50, 50, 10, 10);
	gameover_box->Add_Message("Thank you for playing our game\nPress Escape to exit");
	gameover_box->Setup_Box();
	gameover_box->set_rects();
	gameover_box->set_should_display(true);
}

void End_Menu_Splash::Handle_Keys()
{
	switch (m_p_game->keyDown)
	{
	case(SDLK_ESCAPE) :
		m_b_game_over = true;
		m_b_close_splash = true;
		break;
	}
}

void End_Menu_Splash::Logic()
{

}

void End_Menu_Splash::Render_Back()
{
	SDL_BlitSurface(m_p_game->bg, NULL, m_p_game->screen, NULL);
}

void End_Menu_Splash::Render_Mid()
{
}

void End_Menu_Splash::Render_Front()
{
	gameover_box->Display();
}

bool End_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}