/*
 * Tetromino.h
 *
 *  Created on: May 30, 2018
 *      Author: adolfo
 */

#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <map>
#include <SDL2/SDL.h>
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

class Tetromino
{
public:
	Tetromino(GameScene *gameScene, TetrominoType type, int xIndex, int yIndex);
	~Tetromino();

	static const SDL_Color& GetColor(const int type);
	TetrominoType GetType() const;
	void SetType(TetrominoType type);
	void Move(int dx, int dy);
	bool IsAboveGround(int dy);
	bool IsInbounds(int dx);
	bool IsCollisionFree(int dx, int dy);
	void Rotate();

    static const std::map<int, SDL_Color> mColorDict;
	std::vector<SDL_Point> mCoord;
	int mMatrixSize;
	int mY;
	int mX;

private:
	GameScene *mScene;
	TetrominoType mType;
};

#endif /* TETROMINO_H_ */
