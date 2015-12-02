#include "Game.h"


Game::Game()
	:m_splash(NULL), m_credit_box(NULL)
{
	TTF_Init(); //initialise SDL_TTF library (third party library to deal with fonts and displaying text)
}


Game::~Game()
{
	//free memory
	delete m_splash;
	m_splash = NULL;
	delete m_credit_box;
	m_credit_box = NULL;
}

void Game::Setup()
{
	//setup the final display screen
	m_credit_box = new Text_Box(); //initialise box
	m_credit_box->set_font("fonts/game_font.ttf", 30); //set box font and size
	m_credit_box->set_color(200, 0, 0); //set font colour
	m_credit_box->Position_Setting(50, 50, 10, 10); //position the box (left position, top position, x margin, y margin)
	m_credit_box->Add_Message("CREDITS\nJoseph Adams\nNiall Maple\nKyle Thomas\nEdward Hawksowrth"); //add text to box
	m_credit_box->Setup_Box(); //create (non-visible) aw_sprite to act as positioning agent
	m_credit_box->set_rects(); //set up the rects for each line of text

	Run(); //call the function that runs the actual game
}

void Game::Run()
{
	m_splash = new Start_Menu_Splash(this); //load the start screen
	if (m_splash->Run()) //run splash screen and return whether game should end
	{
		gameover = true; //if game should end then set gameover true
		return; //and return out of function
	}

	m_splash = new Play_Screen(this); //load the play_screen (this contains the code for actually playing all the levels)
	if (m_splash->Run()) // run play screen and return whether game should end
	{
		gameover = true; //if game should end then set gameover true
		return; //and return out of function
	}
	m_splash = new End_Menu_Splash(this); //load the end splash
	if (m_splash->Run()) //run end splash and return whether game should end
	{
		gameover = true; //if game should end then set gameover true
		return; //and return out of function
	}

	//once this function exists naturally the next call will be to the Draw() function (made by GameBase) which will display the credits.
}

void Game::Draw()
{
	m_credit_box->Display(); //display the credits
}