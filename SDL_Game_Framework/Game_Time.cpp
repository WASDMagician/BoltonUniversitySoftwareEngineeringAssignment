#include "Game_Time.h"


Game_Time::Game_Time()
	:m_last_call_time(0)
{
}


Game_Time::~Game_Time()
{
}


float Game_Time::Seconds_Since_Start()
{
	return std::clock();

}

float Game_Time::Milliseconds_Since_Start()
{
	return std::clock() / 1000;
}

float Game_Time::Seconds_Since_Last_Call()
{
	
	float elapsed = (std::clock() - m_last_call_time);
	m_last_call_time = std::clock();
	return elapsed;
}

float Game_Time::Milliseconds_Since_Last_Call()
{
	float elapsed = (std::clock() - m_last_call_time);
	m_last_call_time = std::clock();
	return elapsed / 1000;
	
}