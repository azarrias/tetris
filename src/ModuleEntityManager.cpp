/*
 * ModuleEntityManager.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameObject.h"
#include "Globals.h"
#include "ModuleEntityManager.h"

ModuleEntityManager::ModuleEntityManager()
{
	// TODO - Move to scene
	mPlayingTetromino = dynamic_cast<Tetromino*>(CreateGameObject(GameObjectType::TETROMINO,
		SCREEN_WIDTH / 2 - BALL_WIDTH / 2,
		SCREEN_HEIGHT / 2 - BALL_HEIGHT / 2,
		BALL_WIDTH,
		BALL_HEIGHT));
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

GameObject* ModuleEntityManager::CreateGameObject(GameObjectType type, int xPos, int yPos, int width, int height)
{
	static_assert(GameObjectType::UNKNOWN == 1, "Warning: Some GameObject type is not handled!");
	GameObject* go = nullptr;
	switch (type) {
		case GameObjectType::TETROMINO:
			go = new Tetromino(TetrominoType::TETROMINO_J, xPos, yPos, width, height);
			break;
		case GameObjectType::UNKNOWN:
			go = new GameObject(GameObjectType::UNKNOWN, xPos, yPos, width, height);
	}

	if (go) {
		mEntities.push_back(go);
	}

	return go;
}

bool ModuleEntityManager::Init()
{
	return true;
}

bool ModuleEntityManager::Update()
{
	for (std::vector<GameObject*>::iterator it = mEntities.begin(); it != mEntities.end(); ++it)
	{
		(*it)->UpdateVel();
		(*it)->UpdatePos();
	}

	return true;
}
