/*
 * Globals.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <cmath>
#include <string>

class GameManager;

// Game setup constants
const int SPAWN_AREA_CELLS = 4;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int BOARD_CELLS_X = 10;
const int BOARD_CELLS_Y = 20;
const int SCREEN_CELLS_Y = 24;
const int CELL_SIDE_SIZE = static_cast<int>(std::floor(SCREEN_HEIGHT / SCREEN_CELLS_Y));
const int BOARD_WIDTH = CELL_SIDE_SIZE * BOARD_CELLS_X;
const int BOARD_HEIGHT = CELL_SIDE_SIZE * BOARD_CELLS_Y;
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
