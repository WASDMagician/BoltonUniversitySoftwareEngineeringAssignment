#ifndef _PLAY_SPLASH_H_
#define _PLAY_SPLASH_H_

#include "Character_Factory_Implementation.h"
#include "Level.h"

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

	void Move(int xAmount, int yAmount);

	void Render();
	void Render_Back();
	void Render_Mid();
	void Render_Front();

	bool Run();

	void Toggle_Pause();

	char* m_unpaused_image_path;
	char* m_paused_image_path;

private:
	
	Level *m_level;
	Character_Factory_Implementation* char_factory;
	Character *m_player;

	bool m_b_paused;
};

#endif // _PLAY_SPLASH_H_