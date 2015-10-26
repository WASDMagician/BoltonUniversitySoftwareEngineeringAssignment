#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

#include <vector>

class Game; // forward declaration

class Splash_Screen
{
public:
	Splash_Screen();
	Splash_Screen(Game* game, char* bgImg);
	~Splash_Screen();

	//virtual means if the function will be different in child classes
	virtual void process_keys() = 0; // processes transition of screens
	virtual void start();
	virtual bool Run();
	bool is_game_over();

private:
	Game* m_p_game; // game pointer to game object
	bool m_b_close_splash;
	bool m_b_game_over;
};

#endif
