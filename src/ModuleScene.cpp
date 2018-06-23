/*
 * ModuleScene.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include <cmath>
#include "GameManager.h"
#include "Globals.h"
#include "ModuleEntityManager.h"
#include "ModuleScene.h"
#include "Random.h"

ModuleScene::ModuleScene()
{
	mBoardRect = { SCREEN_WIDTH / 2 - BOARD_WIDTH / 2, SCREEN_HEIGHT / 2 - BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT };
	mBoard = std::vector<std::vector<int>>(BOARD_CELLS_Y, std::vector<int>(BOARD_CELLS_X));
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

bool ModuleScene::Update()
{
    // Update board
	Tetromino *t = game->mEntities->mPlayingTetromino;

	for (SDL_Point coord : t->mCoord)
	{
		game->mScene->mBoard[t->mX + coord.x][t->mY + coord.y] = t->GetType();
	}

	return true;
}
