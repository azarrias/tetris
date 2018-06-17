/*
 * Tetromino.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Tetromino.h"

Tetromino::Tetromino()
: GameObject()
{}

Tetromino::Tetromino(int xPos, int yPos, int width, int height)
: GameObject(GameObjectType::TETROMINO, xPos, yPos, width, height)
{}

Tetromino::~Tetromino()
{}

void Tetromino::UpdatePos()
{
    mRect.x += mVelocity.mX;
	if (mRect.x < 0 || mRect.x + mRect.w > SCREEN_WIDTH)
	{
		mRect.x -= mVelocity.mX;
	}

	mRect.y += mVelocity.mY;
	if (mRect.y < 0 || mRect.y + mRect.h > SCREEN_HEIGHT)
	{
		mRect.y -= mVelocity.mY;
	}
}
