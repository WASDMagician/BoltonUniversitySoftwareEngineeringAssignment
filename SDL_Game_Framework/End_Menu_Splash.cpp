#include "End_Menu_Splash.h"
#include "Game.h"

End_Menu_Splash::End_Menu_Splash(Game *pGame)
: Splash_Screen(pGame), m_gameover_box(NULL)
{
	m_gameover_box = new Text_Box(); //initialise gameover box
}

End_Menu_Splash::~End_Menu_Splash(void)
{
	//free memory
	delete m_gameover_box;
	m_gameover_box = NULL;

}

void End_Menu_Splash::Setup()
{
	//setup gameover box
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
	if (m_game->keyUp == SDLK_ESCAPE) //use if statement to deal with single key press
	{
		m_game_over = true;
	}
}

void End_Menu_Splash::Render_Back()
{
	SDL_FillRect(m_game->screen, NULL, 0x000000); //bleh, not sure about this, stops tearing
}

void End_Menu_Splash::Render_Mid()
{
	m_gameover_box->Display(); //display gamebox
}

bool End_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}