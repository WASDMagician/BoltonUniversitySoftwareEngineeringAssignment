#ifndef _GAME_TIME_H_
#define _GAME_TIME_H_

#include <iostream>
#include <ctime>

class Game_Time
{
public:
	Game_Time();
	~Game_Time();

	double Seconds_Since_Start();
	double Milliseconds_Since_Start();
	double Seconds_Since_Last_Call();
	double Milliseconds_Since_Last_Call();

private:
	double m_last_call_time;
};

#endif //_GAME_TIME_H_