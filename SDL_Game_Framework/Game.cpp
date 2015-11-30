#include "Game.h"


Game::Game()
	:m_splash(NULL), m_credit_box(NULL)
{
	m_timer = new Game_Time();
	TTF_Init();
}


Game::~Game()
{
	delete m_splash;
	m_splash = NULL;
	delete m_credit_box;
	m_credit_box = NULL;
	delete m_timer;
	m_timer = NULL;
}

void Game::Setup()
{
	m_credit_box = new Text_Box();
	m_credit_box->set_font("fonts/game_font.ttf", 30);
	m_credit_box->set_color(200, 0, 0);
	m_credit_box->Position_Setting(50, 50, 10, 10);
	m_credit_box->Add_Message("CREDITS\nJoseph Adams\nNiall Maple\nKyle Thomas\nEdward Hawksowrth");
	m_credit_box->Setup_Box();
	m_credit_box->set_rects();
	Run();
}

void Game::Run()
{
	m_splash = new Start_Menu_Splash(this);
	m_splash->Run();
	m_splash = new Play_Screen(this);
	m_splash->Run();
	m_splash = new End_Menu_Splash(this);
	m_splash->Run();	
}

void Game::Draw()
{
	m_credit_box->Display();
}