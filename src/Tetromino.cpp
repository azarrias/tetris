/*
 * Tetromino.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameScene.h"
#include "Globals.h"
#include "ModuleSceneManager.h"
#include "Tetromino.h"
#include <vector>

const std::map<int, SDL_Color> Tetromino::mColorDict = {
	{ TetrominoType::TETROMINO_I, { 0xFF, 0x00, 0x00, 0xFF } }, // Red
    { TetrominoType::TETROMINO_J, { 0xFF, 0xFF, 0xFF, 0xFF } }, // White
	{ TetrominoType::TETROMINO_L, { 0xFF, 0x00, 0xFF, 0xFF } }, // Magenta
	{ TetrominoType::TETROMINO_O, { 0x00, 0x00, 0xFF, 0xFF } }, // Blue
	{ TetrominoType::TETROMINO_S, { 0x00, 0xFF, 0x00, 0xFF } }, // Green
    { TetrominoType::TETROMINO_T, { 0xA5, 0x2A, 0x2A, 0xFF } }, // Brown
    { TetrominoType::TETROMINO_Z, { 0x00, 0xFF, 0xFF, 0xFF } }  // Cyan
};

Tetromino::Tetromino(GameScene *gameScene, TetrominoType type, int xIndex, int yIndex)
	: mScene(gameScene), mX(xIndex), mY(yIndex)
{
	SetType(type);
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

void Tetromino::SetType(TetrominoType type)
{
	/* X,Y coordinates and indexes that define tetromino shapes I and O
	*
	*      0  1  2  3
	*   +-------------
	* 0 |  0  1  2  3
	* 1 |  4  5  6  7
	* 2 |  8  9 10 11
	* 3 | 12 13 14 15
	*
	* For the other shapes, the rotation will feel more natural with a 3x3 matrix:
	*
	*      0  1  2
	*   +----------
	* 0 |  0  1  2
	* 1 |  3  4  5
	* 2 |  6  7  8
	*/

	switch (type)
	{
	case TetrominoType::TETROMINO_I:
		mCoord = { { 0, 1 },{ 1, 1 },{ 2, 1 },{ 3, 1 } };
		mMatrixSize = 4;
		break;
	case TetrominoType::TETROMINO_J:
		mCoord = { { 0, 1 },{ 0, 2 },{ 1, 2 },{ 2, 2 } };
		mMatrixSize = 3;
		break;
	case TetrominoType::TETROMINO_L:
		mCoord = { { 0, 2 },{ 1, 2 },{ 2, 2 },{ 2, 1 } };
		mMatrixSize = 3;
		break;
	case TetrominoType::TETROMINO_O:
		mCoord = { { 1, 1 },{ 2, 1 },{ 1, 2 },{ 2, 2 } };
		mMatrixSize = 4;
		break;
	case TetrominoType::TETROMINO_S:
		mCoord = { { 0, 2 },{ 1, 2 },{ 1, 1 },{ 2, 1 } };
		mMatrixSize = 3;
		break;
	case TetrominoType::TETROMINO_T:
		mCoord = { { 0, 2 },{ 1, 2 },{ 1, 1 },{ 2, 2 } };
		mMatrixSize = 3;
		break;
	case TetrominoType::TETROMINO_Z:
		mCoord = { { 0, 1 },{ 1, 1 },{ 1, 2 },{ 2, 2 } };
		mMatrixSize = 3;
		break;
	}

	mType = type;
}

void Tetromino::Move(int dx, int dy)
{
	mX += dx;
	mY += dy;
}

bool Tetromino::IsInbounds(int dx)
{
	const int mNewX = mX + dx;
	
	for (SDL_Point coord : mCoord)
	{
		if (mNewX + coord.x < 0 || mNewX + coord.x > BOARD_CELLS_X - 1)
			return false;
	}

	return true;
}

bool Tetromino::IsAboveGround(int dy)
{
	const int mNewY = mY + dy;

	for (SDL_Point coord : mCoord)
	{
		if (mNewY + coord.y > mScene->mBoard.size() - 1)
		{
			return false;
		}
	}

	return true;
}

bool Tetromino::IsCollisionFree(int dx, int dy)
{
	const int mNewX = mX + dx;
	const int mNewY = mY + dy;

	for (SDL_Point coord : mCoord)
	{
		if (mScene->mBoard[mNewY + coord.y][mNewX + coord.x] != 0)
		{
			return false;
		}
	}

	return true;
}

void Tetromino::Rotate()
{
	// Check for requested new coordinates
	std::vector<SDL_Point> newCoords(mCoord);

	for (SDL_Point &coord : newCoords)
	{
		std::swap(coord.x, coord.y);
		coord.y = mMatrixSize - 1 - coord.y;

		// Do this just to keep the tetromino within bounds
		while (mX + coord.x < 0)
			mX += 1;

		while (mX + coord.x > BOARD_CELLS_X - 1)
			mX -= 1;

		if (mScene->mBoard[mY + coord.y][mX + coord.x] != 0)
			return;
	}

	// If they are available, we can rotate the piece
	mCoord = newCoords;
}
