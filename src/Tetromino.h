/*
 * Paddle.h
 *
 *  Created on: May 30, 2018
 *      Author: adolfo
 */

#ifndef TETROMINO_H_
#define TETROMINO_H_

#include "GameObject.h"
#include <map>
#include <vector>

enum TetrominoType
{
	TETROMINO_I = 1,
	TETROMINO_O,
	TETROMINO_T,
	TETROMINO_S,
	TETROMINO_Z,
	TETROMINO_J,
	TETROMINO_L,
	TETROMINO_FIRST = TETROMINO_I,
	TETROMINO_LAST = TETROMINO_L
};

class Tetromino : public GameObject
{
public:
	Tetromino(TetrominoType type, int xPos, int yPos, int width, int height);
	~Tetromino() override;

	void UpdatePos() override;

	std::vector<SDL_Point> mCoord;

private:
	static const std::map<int, SDL_Color> mColorDict;
};

#endif /* TETROMINO_H_ */
