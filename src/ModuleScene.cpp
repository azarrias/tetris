/*
 * ModuleScene.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include <cmath>
#include "GameManager.h"
#include "Globals.h"
#include "ModuleScene.h"
#include "Random.h"
#include "Tetromino.h"

ModuleScene::ModuleScene()
{
	mBoardRect = { SCREEN_WIDTH / 2 - BOARD_WIDTH / 2, SCREEN_HEIGHT / 2 - BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT };
	mBoard = std::vector<std::vector<int>>(BOARD_CELLS_Y, std::vector<int>(BOARD_CELLS_X));
	SpawnTetromino();
}

ModuleScene::~ModuleScene()
{}

bool ModuleScene::CleanUp()
{
	return true;
}

bool ModuleScene::Init()
{

	return true;
}

void ModuleScene::SpawnTetromino()
{
	mPlayingTetromino = new Tetromino(TetrominoType::TETROMINO_J, 3, 0);
}

bool ModuleScene::Update()
{
    // Update board
	for (SDL_Point coord : mPlayingTetromino->mCoord)
	{
		game->mScene->mBoard[mPlayingTetromino->mX + coord.x][mPlayingTetromino->mY + coord.y] = mPlayingTetromino->GetType();
	}

	return true;
}
