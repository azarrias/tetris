/*
 * Tetromino.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include "Tetromino.h"

const std::map<int, SDL_Color> Tetromino::mColorDict = {
	{ TetrominoType::I, { 0xFF, 0x00, 0x00, 0xFF } }, // Red
    { TetrominoType::J, { 0xFF, 0xFF, 0xFF, 0xFF } }, // White
	{ TetrominoType::L, { 0xFF, 0x00, 0xFF, 0xFF } }, // Magenta
	{ TetrominoType::O, { 0x00, 0x00, 0xFF, 0xFF } }, // Blue
	{ TetrominoType::S, { 0x00, 0xFF, 0x00, 0xFF } }, // Green
    { TetrominoType::T, { 0xA5, 0x2A, 0x2A, 0xFF } }, // Brown
    { TetrominoType::Z, { 0x00, 0xFF, 0xFF, 0xFF } }  // Cyan
};

Tetromino::Tetromino(TetrominoType type, int xPos, int yPos, int width, int height)
: GameObject(GameObjectType::TETROMINO, xPos, yPos, width, height)
{
	switch (type)
	{
	case TetrominoType::I:
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		break;
	case TetrominoType::J:
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case TetrominoType::L:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case TetrominoType::O:
		mShape.push_back({ 0, 0, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case TetrominoType::S:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case TetrominoType::T:
		mShape.push_back({ 0, 1, 0, 0 });
		mShape.push_back({ 0, 1, 1, 0 });
		mShape.push_back({ 0, 0, 1, 0 });
		mShape.push_back({ 0, 0, 0, 0 });
		break;
	case TetrominoType::Z:
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
