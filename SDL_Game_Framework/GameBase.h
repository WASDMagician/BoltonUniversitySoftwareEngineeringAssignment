// Version 1.0. Copyright Peter Lager and the University of Bolton. 
// Do what you like with the program, but please include your
// sourcecode with any distribution and retain my copyright notices
//
// Version 1.1 - protected access commented out for functions. SM.

#pragma once

#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "audiomanager.h"
#include "AWSprite.h"
#include "awfont.h"

#include "console.h"
#include "random.h"

using namespace std;
using namespace con;
using namespace random;

#define SAFE_DELETE_PTR(ptr) if( (ptr) != NULL ) delete (ptr); (ptr) = NULL;
#define SAFE_DELETE_ARY(ary) if( (ary) != NULL ) delete[] (ary); (ary) = NULL;

// Colour constants 
const int GREEN = 0;
const int WHITE = 1;
const int RED = 2;

/**
This has the core functionality to create simple games. <br>

All games should be built from its own game class that inherits
from this class. <br>
*/
class GameBase
{
public:
	GameBase(void);
	virtual ~GameBase(void);

	/**
	You should override this method to provide code to setup your
	game variables and state.
	*/
	virtual void Setup(){}
	/**
	Once your game has been created and initialised (using setup)
	call this method to start the game.
	*/
	virtual void Start();

//protected:	//commented out by SM so that functions can be accessed from an object ptr
	SDL_Surface* screen;
	SDL_Surface* bg;
	AWFont *fs_white, *fs_green, *fs_red;

	/*
	The values in these variables are updated every iteration of the game loop
	and should be used in the onKey??? and onMouse??? methods to change the game
	variables and state.
	*/
	int mouseX, mouseY;
	int pmouseX, pmouseY;
	int mouseButton;
	int keyDown, keyUp;
	bool ctrlPressed, shiftPressed, altPressed;

	boolean gameover;

	// These are used to store the width and height of the display area
	// and are initialised when you create the game object.
	int width, height;

	virtual void Logic(){}
	virtual void Draw(){}
	virtual void Post(){}

	virtual void GetUserInput();

	int EnableKeyRepeat(int first = 70, int repeat = 70);

	/**
	Set the background colour for the display. The parameters should 
	be in the range 0-255 inclusive.
	*/
	void SetBackground(int red, int green, int blue);
	/**
	Set the backgorund image to be used for the display area. It makes
	sense if the image is the same size as the display area as scaling 
	is not applied to the image.
	*/
	void SetBackground(char *imageFileName);

	/**
	Add a sound effect for later playing.
	@param filename the filename of the audio file to load.
	@param name this should be unique for eah sound effect added.
	*/
	bool addSound(char* filename, string name);
	/**
	Play the sound effect (expect some latency)
	@param name the unique name of the sound effect to play
	*/
	void PlaySound(string name);

	/*
	These  provide nill functionality event handlers you should
	override these if needed.
	*/
	virtual void OnMousePressed(){}
	virtual void OnMouseReleased(){}
	virtual void OnMouseMoved(){}
	virtual void OnKeyPressed(){}
	virtual void OnKeyReleased(){}

	/**
	This is the main gameloop and is called when the game is started. <br>
	Although it is possible to override this method in your own game class
	this is not recommended unless you really know what you are doing!!!
	*/
	void GameLoop();

	/**
	These methods are used to display text on the screen at a given position.
	Three colours are available GREEN, WHITE and RED if you don't specify a
	colour then it will use green text.
	@param value the value to display can be of type string, char array, 
				 integer or float
	@param x the horizontal pixel position to start printing
	@param y the vertical (character top) pixel position to use
	@param color the colour to use (choice of GREEN, WHITE or RED)
	*/
	int Print(string value, int x, int y, int color = GREEN);
	int Print(const char* value, int x, int y, int color = GREEN);
	int Print(int value, int x, int y, int color = GREEN);
	int Print(float value, int x, int y, int color = GREEN);

private:
	AWFont* GetFontToUse(int color);

private:
	static SDL_Surface* screen_surface;
	static SDL_Surface* background_surface;

protected:
	/**
	Get a surface for the display of the given size and colour
	*/
	static SDL_Surface* GetSurface(int width, int height, int red, int green, int blue);

public:
	/**
	This method should be called before you create your game object otherwise your
	program will crash. <br>
	It creates the window with a display area width x height and sets the background
	to black. <br>
	You can use the setBackground methods to change the background colour or
	provide an image to use.
	*/
	static int InitSDL(int width, int height);

};

