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
	I,
	O,
	T,
	S,
	Z,
	J,
	L,
	NR_OF_TETROMINO_TYPES
};

class Tetromino : public GameObject
{
public:
	Tetromino(TetrominoType type, int xPos, int yPos, int width, int height);
	~Tetromino() override;

	void UpdatePos() override;

	std::vector<std::vector<int>> mShape;

private:
	static const std::map<int, SDL_Color> mColorDict;
};

#endif /* TETROMINO_H_ */
