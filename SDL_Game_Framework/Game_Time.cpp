#include "Game_Time.h"


Game_Time::Game_Time()
	:m_last_call_time(0)
{
}


Game_Time::~Game_Time()
{
}


double Game_Time::Seconds_Since_Start()
{
	return std::clock() / (double)CLOCKS_PER_SEC;

}

double Game_Time::Milliseconds_Since_Start()
{
	return std::clock();
}

double Game_Time::Seconds_Since_Last_Call()
{
	
	double elapsed = (std::clock() - m_last_call_time) / (double)CLOCKS_PER_SEC;
	m_last_call_time = std::clock();
	return elapsed;
}

double Game_Time::Milliseconds_Since_Last_Call()
{
	double elapsed = (std::clock() - m_last_call_time);
	m_last_call_time = std::clock();
	return elapsed;
	
}