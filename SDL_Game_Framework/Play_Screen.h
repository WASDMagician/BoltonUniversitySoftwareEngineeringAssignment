#ifndef _PLAY_SPLASH_H_
#define _PLAY_SPLASH_H_

#include "Splash_Screen.h"
class Play_Screen :
	public Splash_Screen
{
public:
	Play_Screen();
	Play_Screen(Game *pGame, char* bgImg);
	~Play_Screen();

	void Setup();
	void Logic();
	void Handle_Keys();

	void Render();
	void Render_Back();
	void Render_Mid();
	void Render_Front();

	bool Run();

	void Toggle_Pause();

	char* m_unpaused_image_path;
	char* m_paused_image_path;

private:
	
	bool m_b_paused;
};

#endif // _PLAY_SPLASH_H_