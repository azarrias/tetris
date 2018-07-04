/*
 * ModuleScene.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include <algorithm>
#include <cmath>
#include "GameManager.h"
#include "Globals.h"
#include "ModuleScene.h"
#include "Random.h"
#include <unordered_set>
#include <set>
#include "Tetromino.h"

ModuleScene::ModuleScene()
{
	mBoardRect = { SCREEN_WIDTH / 2 - BOARD_WIDTH / 2, SCREEN_HEIGHT / 2 - BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT };
}

ModuleScene::~ModuleScene()
{}

void ModuleScene::CheckForLines()
{
	// Keep record of what Y coordinates have been checked for lines
	std::unordered_set<int> checked_coord_y;
	std::vector<int> complete_lines_idx;

	// Check for complete lines
	for (SDL_Point coord : mPlayingTetromino->mCoord)
	{
		// Check for this line if it has not been already checked
		if (checked_coord_y.find(coord.y) == checked_coord_y.end())
		{
			int line_idx = mPlayingTetromino->mY + coord.y;
			std::vector<int>* line = &game->mScene->mBoard[line_idx];
			int count = std::count_if(line->begin(), line->end(), [](int i) { return i != 0; });
			if (count == BOARD_CELLS_X)
			{
				complete_lines_idx.push_back(line_idx);
			}

			checked_coord_y.insert(coord.y);
		}
	}

	// Remove all complete lines
	std::sort(complete_lines_idx.begin(), complete_lines_idx.end());
	for (std::vector<int>::reverse_iterator it = complete_lines_idx.rbegin(); it != complete_lines_idx.rend(); ++it)
	{
		game->mScene->mBoard.erase(game->mScene->mBoard.begin() + *it);
	}

	// Insert new lines at the beginning (top) of the board
	for (const int line_idx : complete_lines_idx)
	{
		game->mScene->mBoard.insert(game->mScene->mBoard.begin(), std::vector<int>(BOARD_CELLS_X));
	}
}

bool ModuleScene::CleanUp()
{
	if (mPlayingTetromino)
	{
		delete mPlayingTetromino;
		mPlayingTetromino = nullptr;
	}

	return true;
}

bool ModuleScene::Init()
{
	mBoard = std::vector<std::vector<int>>(BOARD_CELLS_Y + SPAWN_AREA_CELLS, std::vector<int>(BOARD_CELLS_X));
	mTimer.reset();
	mPlayingTetromino = new Tetromino(static_cast<TetrominoType>(Random::GetRandom<int>(TetrominoType::TETROMINO_FIRST, TetrominoType::TETROMINO_LAST)), 3, 3);
	return true;
}

void ModuleScene::LockCurrentTetromino()
{
	for (SDL_Point coord : mPlayingTetromino->mCoord)
	{
		game->mScene->mBoard[mPlayingTetromino->mY + coord.y][mPlayingTetromino->mX + coord.x] = mPlayingTetromino->GetType();
	}
}

void ModuleScene::SpawnTetromino()
{
	mPlayingTetromino->SetType(static_cast<TetrominoType>(Random::GetRandom<int>(TetrominoType::TETROMINO_FIRST, TetrominoType::TETROMINO_LAST)));
	mPlayingTetromino->mX = 3;
	mPlayingTetromino->mY = 2;

	// If no existing block is in the tetromino's path, immediately drop one space, otherwise game over
	if(mPlayingTetromino->IsCollisionFree(0, 1))
	{
		mPlayingTetromino->Move(0, 1);
	}
	else
	{
		// TODO - Add game over screen
		Init();
	}
}

bool ModuleScene::Update()
{
	if (mTimer.getDelta() >= 750)
	{
		if (mPlayingTetromino->IsAboveGround(1) && mPlayingTetromino->IsCollisionFree(0, 1))
		{
			mPlayingTetromino->Move(0, 1);
		}
		else
		{
			game->mScene->LockCurrentTetromino();
			game->mScene->CheckForLines();
			game->mScene->SpawnTetromino();
		}

		mTimer.reset();
	}

	return true;
}
