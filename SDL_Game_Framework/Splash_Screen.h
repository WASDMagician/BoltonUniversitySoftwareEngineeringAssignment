#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

#include <vector>
#include "Text_Box.h"

class Game; // forward declaration

class Splash_Screen
{
public:
	Splash_Screen();
	Splash_Screen(Game* m_game);
	~Splash_Screen();

	virtual void Start();
	virtual void Setup();
	virtual void Logic();

	virtual void Handle_Keys();
	
	virtual void Render();

	virtual bool Run();
	bool is_game_over();

protected:
	virtual void Render_Back();
	virtual void Render_Mid();
	virtual void Render_Front();

	Game* m_game; // game pointer to game object
	bool m_close_splash;
	bool m_game_over;
};

#endif
