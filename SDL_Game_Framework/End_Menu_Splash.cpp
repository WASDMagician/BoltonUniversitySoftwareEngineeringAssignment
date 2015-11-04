#include "End_Menu_Splash.h"
#include "Game.h"

End_Menu_Splash::End_Menu_Splash()
	:Splash_Screen(NULL, NULL, "End_Menu_Splash")
{

}

End_Menu_Splash::End_Menu_Splash(Game *pGame, char* bgImg)
	: Splash_Screen(pGame, bgImg, "End_Menu_Splash")
{

}

End_Menu_Splash::~End_Menu_Splash(void)
{

}

void End_Menu_Splash::Setup()
{

}

void End_Menu_Splash::Handle_Keys()
{
	switch (m_p_game->keyDown)
	{
	case(SDLK_SPACE) :
		printf("End");
		break;
	case(SDLK_RETURN):
		m_b_game_over = true;
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
}

bool End_Menu_Splash::Run()
{
	Start();
	return is_game_over();
}