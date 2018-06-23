/*
 * Tetromino.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Tetromino.h"

const std::map<int, SDL_Color> Tetromino::mColorDict = {
	{ TetrominoType::TETROMINO_I, { 0xFF, 0x00, 0x00, 0xFF } }, // Red
    { TetrominoType::TETROMINO_J, { 0xFF, 0xFF, 0xFF, 0xFF } }, // White
	{ TetrominoType::TETROMINO_L, { 0xFF, 0x00, 0xFF, 0xFF } }, // Magenta
	{ TetrominoType::TETROMINO_O, { 0x00, 0x00, 0xFF, 0xFF } }, // Blue
	{ TetrominoType::TETROMINO_S, { 0x00, 0xFF, 0x00, 0xFF } }, // Green
    { TetrominoType::TETROMINO_T, { 0xA5, 0x2A, 0x2A, 0xFF } }, // Brown
    { TetrominoType::TETROMINO_Z, { 0x00, 0xFF, 0xFF, 0xFF } }  // Cyan
};

Tetromino::Tetromino(TetrominoType type, int xIndex, int yIndex)
	: mType(type), mX(xIndex), mY(yIndex)
{
	/* X,Y coordinates and indexes that define tetromino shapes
	 * 
	 *      0  1  2  3 
	 *   +-------------
     * 0 |  0  1  2  3
	 * 1 |  4  5  6  7
	 * 2 |  8  9 10 11
	 * 3 | 12 13 14 15
	 *
	 */

	switch (type)
	{
	case TetrominoType::TETROMINO_I:
		mCoord = { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } };
		break;
	case TetrominoType::TETROMINO_J:
		mCoord = { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 1, 2 } };
		break;
	case TetrominoType::TETROMINO_L:
		mCoord = { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 2 } };
		break;
	case TetrominoType::TETROMINO_O:
		mCoord = { { 1, 1 }, { 2, 1 }, { 1, 2 }, { 2, 2 } };
		break;
	case TetrominoType::TETROMINO_S:
		mCoord = { { 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 } };
		break;
	case TetrominoType::TETROMINO_T:
		mCoord = { { 1, 1 }, { 2, 0 }, { 2, 1 }, { 2, 2 } };
		break;
	case TetrominoType::TETROMINO_Z:
		mCoord = { { 2, 0 }, { 1, 1 }, { 2, 1 }, { 1, 2 } };
		break;
	}
}

Tetromino::~Tetromino()
{}

const SDL_Color& Tetromino::GetColor(const int type)
{
	return Tetromino::mColorDict.at(type);
}

TetrominoType Tetromino::GetType() const
{
	return mType;
}

void Tetromino::UpdatePos()
{
/*    mRect.x += mVelocity.mX;
	if (mRect.x < 0 || mRect.x + mRect.w > SCREEN_WIDTH)
	{
		mRect.x -= mVelocity.mX;
	}

	mRect.y += mVelocity.mY;
	if (mRect.y < 0 || mRect.y + mRect.h > SCREEN_HEIGHT)
	{
		mRect.y -= mVelocity.mY;
	}*/
}
