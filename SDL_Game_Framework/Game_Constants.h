#ifndef _GAME_CONSTANTS_H_
#define _GAME_CONSTANTS_H_

static int SCRN_WIDTH = 800;
static int SCRN_HEIGHT = 600;

static enum GAME_STATES{START_GAME, PLAY_GAME, PAUSE_GAME, END_GAME};
static char* GAMES[4] {"start", "play", "pause", "end"};
static GAME_STATES CURRENT_STATE;

#endif //_GAME_CONSTANTS_H_