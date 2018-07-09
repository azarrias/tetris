/*
* GameScene.h
*
*  Created on: Jul 09, 2018
*      Author: adolfo
*/

#include <algorithm>
#include "GameManager.h"
#include "GameScene.h"
#include "Globals.h"
#include "Random.h"
#include "Tetromino.h"
#include <unordered_set>

GameScene::GameScene()
{
	mBoardRect = { SCREEN_WIDTH / 2 - BOARD_WIDTH / 2, SCREEN_HEIGHT / 2 - BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT };
}

void GameScene::CheckForLines()
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
			std::vector<int>* line = &mBoard[line_idx];
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
		mBoard.erase(mBoard.begin() + *it);
	}

	// Insert new lines at the beginning (top) of the board
	for (const int line_idx : complete_lines_idx)
	{
		mBoard.insert(mBoard.begin(), std::vector<int>(BOARD_CELLS_X));
	}
}

bool GameScene::CleanUp()
{
	if (mPlayingTetromino)
	{
		delete mPlayingTetromino;
		mPlayingTetromino = nullptr;
	}

	return true;
}

bool GameScene::Init()
{
	mBoard = std::vector<std::vector<int>>(BOARD_CELLS_Y + SPAWN_AREA_CELLS, std::vector<int>(BOARD_CELLS_X));
	mTimer.reset();
	mPlayingTetromino = new Tetromino(this, static_cast<TetrominoType>(Random::GetRandom<int>(TetrominoType::TETROMINO_FIRST, TetrominoType::TETROMINO_LAST)), 3, 3);
	return true;
}

void GameScene::LockCurrentTetromino()
{
	for (SDL_Point coord : mPlayingTetromino->mCoord)
	{
		mBoard[mPlayingTetromino->mY + coord.y][mPlayingTetromino->mX + coord.x] = mPlayingTetromino->GetType();
	}
}

void GameScene::SpawnTetromino()
{
	mPlayingTetromino->SetType(static_cast<TetrominoType>(Random::GetRandom<int>(TetrominoType::TETROMINO_FIRST, TetrominoType::TETROMINO_LAST)));
	mPlayingTetromino->mX = 3;
	mPlayingTetromino->mY = 2;

	// If no existing block is in the tetromino's path, immediately drop one space, otherwise game over
	if (mPlayingTetromino->IsCollisionFree(0, 1))
	{
		mPlayingTetromino->Move(0, 1);
	}
	else
	{
		// TODO - Add game over screen
		Init();
	}
}

bool GameScene::Update()
{
	if (mTimer.getDelta() >= 750)
	{
		if (mPlayingTetromino->IsAboveGround(1) && mPlayingTetromino->IsCollisionFree(0, 1))
		{
			mPlayingTetromino->Move(0, 1);
		}
		else
		{
			LockCurrentTetromino();
			CheckForLines();
			SpawnTetromino();
		}

		mTimer.reset();
	}

	return true;
}
