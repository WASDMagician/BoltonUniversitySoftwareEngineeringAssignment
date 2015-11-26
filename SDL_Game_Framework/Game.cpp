#include "Game.h"
#include "Start_Menu_Splash.h"
#include "Play_Screen.h"
#include "End_Menu_Splash.h"

Game::Game()
:splash(NULL), credit_box(NULL)
{
	TTF_Init();
	
}


Game::~Game()
{
	delete splash;
	splash = NULL;
	delete credit_box;
	credit_box = NULL;

}

void Game::Setup()
{
	credit_box = new Text_Box();
	credit_box->set_font("fonts/game_font.ttf", 30);
	credit_box->set_color(200, 0, 0);
	credit_box->Position_Setting(50, 50, 10, 10);
	credit_box->Add_Message("CREDITS\nJoseph Adams\nNiall Maple\nKyle Thomas\nEdward Hawksowrth");
	credit_box->Setup_Box();
	credit_box->set_rects();
	Run();
}

void Game::Run()
{
	splash = new Start_Menu_Splash(this, "images/splash1.png");
	splash->Run();
	splash = new Play_Screen(this, "images/splash2.png");
	splash->Run();
	splash = new End_Menu_Splash(this, "images/splash1.png");
	splash->Run();	
}

void Game::Draw()
{
	credit_box->Display();
}