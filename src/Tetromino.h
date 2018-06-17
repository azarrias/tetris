/*
 * Paddle.h
 *
 *  Created on: May 30, 2018
 *      Author: adolfo
 */

#ifndef TETROMINO_H_
#define TETROMINO_H_

#include "GameObject.h"

class Tetromino : public GameObject
{
public:
	Tetromino();
	Tetromino(int xPos, int yPos, int width, int height);
	~Tetromino() override;

	void UpdatePos() override;
};

#endif /* TETROMINO_H_ */
