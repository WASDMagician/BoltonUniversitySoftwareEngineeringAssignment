#ifndef _GAME_TIME_H_
#define _GAME_TIME_H_

#include <iostream>
#include <ctime>

class Game_Time
{
public:
	Game_Time();
	~Game_Time();

	float Seconds_Since_Start();
	float Milliseconds_Since_Start();
	float Seconds_Since_Last_Call();
	float Milliseconds_Since_Last_Call();

private:
	float m_last_call_time;
};

#endif //_GAME_TIME_H_