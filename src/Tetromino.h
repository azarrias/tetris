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

enum CellType
{
	NO_TETROMINO,
	TETROMINO_I,
	TETROMINO_O,
	TETROMINO_T,
	TETROMINO_S,
	TETROMINO_Z,
	TETROMINO_J,
	TETROMINO_L,
	NR_OF_CELL_TYPES
};

class Tetromino : public GameObject
{
public:
	Tetromino(CellType type, int xPos, int yPos, int width, int height);
	~Tetromino() override;

	void UpdatePos() override;

	std::vector<SDL_Point> mCoord;
//	std::vector<std::vector<int>> mShape;

private:
	static const std::map<int, SDL_Color> mColorDict;
};

#endif /* TETROMINO_H_ */
