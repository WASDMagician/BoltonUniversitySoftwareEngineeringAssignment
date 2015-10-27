#ifndef _SPLASH_SCREEN_H_
#define _SPLASH_SCREEN_H_

#include <vector>

class Game; // forward declaration

class Splash_Screen
{
public:
	Splash_Screen();
	Splash_Screen(Game* game, char* bgImg, std::string screen);
	~Splash_Screen();

	//virtual means if the function will be different in child classes
	void Process_Keys(); // processes transition of screens

	void Handle_Start_Keys();
	void Handle_Pause_Keys();
	void Handle_End_Keys();

	virtual void Start();
	virtual bool Run();
	bool is_game_over();

private:
	Game* m_p_game; // game pointer to game object
	bool m_b_close_splash;
	bool m_b_game_over;

protected:
	std::string m_screen;
};

#endif
