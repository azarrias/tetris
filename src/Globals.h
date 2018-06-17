/*
 * Globals.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <string>

class GameManager;

// Game setup constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PADDLE_BORDER_OFFSET = 20;
const int PADDLE_HEIGHT = 100;
const int PADDLE_WIDTH = 20;
const int BALL_HEIGHT = 20;
const int BALL_WIDTH = 20;
const int PADDLE_VELOCITY_DELTA = 10;
const char * const FONT_PATH_BOLD = "assets/disposabledroid-bb.bold.ttf";
const char * const FONT_PATH_NORMAL = "assets/disposabledroid-bb.regular.ttf";
const int FONT_SIZE = 50;
const int SCORE_OFFSET_Y = 10;
const int SCORE_OFFSET_X = 30;

enum MainState
{
	MAIN_INIT,
	MAIN_UPDATE,
	MAIN_CLEANUP,
	MAIN_EXIT
};

extern GameManager *game;

#endif /* GLOBALS_H_ */
