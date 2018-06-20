/*
 * Tetromino.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Tetromino.h"

const std::map<int, SDL_Color> Tetromino::mColorDict = {
	{ CellType::TETROMINO_I, { 0xFF, 0x00, 0x00, 0xFF } }, // Red
    { CellType::TETROMINO_J, { 0xFF, 0xFF, 0xFF, 0xFF } }, // White
	{ CellType::TETROMINO_L, { 0xFF, 0x00, 0xFF, 0xFF } }, // Magenta
	{ CellType::TETROMINO_O, { 0x00, 0x00, 0xFF, 0xFF } }, // Blue
	{ CellType::TETROMINO_S, { 0x00, 0xFF, 0x00, 0xFF } }, // Green
    { CellType::TETROMINO_T, { 0xA5, 0x2A, 0x2A, 0xFF } }, // Brown
    { CellType::TETROMINO_Z, { 0x00, 0xFF, 0xFF, 0xFF } }  // Cyan
};

Tetromino::Tetromino(CellType type, int xPos, int yPos, int width, int height)
: GameObject(GameObjectType::TETROMINO, xPos, yPos, width, height)
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
	case CellType::TETROMINO_I:
		mCoord = { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } };
		break;
	case CellType::TETROMINO_J:
		mCoord = { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 1, 2 } };
		break;
	case CellType::TETROMINO_L:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case CellType::TETROMINO_O:
		mShape.push_back({ 0, 0, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case CellType::TETROMINO_S:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case CellType::TETROMINO_T:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case CellType::TETROMINO_Z:
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	}
}

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
