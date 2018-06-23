/*
 * ModuleEntityManager.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"
#include "ModuleScene.h"

ModuleEntityManager::ModuleEntityManager()
{
	// TODO - Move to scene
	mPlayingTetromino = CreateTetromino(2, 0);
}

ModuleEntityManager::~ModuleEntityManager()
{
	if(mPlayingTetromino)
	{
		delete mPlayingTetromino;
		mPlayingTetromino = nullptr;
	}
}

bool ModuleEntityManager::CleanUp()
{
	return true;
}

Tetromino* ModuleEntityManager::CreateTetromino(int xIndex, int yIndex)
{
	Tetromino* t = new Tetromino(TetrominoType::TETROMINO_J, xIndex, yIndex);

	if (t) {
		mTetrominoes.push_back(t);
	}

	return t;
}

bool ModuleEntityManager::Init()
{
	return true;
}

bool ModuleEntityManager::Update()
{
	for (std::vector<Tetromino*>::iterator it = mTetrominoes.begin(); it != mTetrominoes.end(); ++it)
	{
		(*it)->UpdatePos();
	}

	return true;
}
