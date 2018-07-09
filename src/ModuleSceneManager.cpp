/*
 * ModuleSceneManager.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameScene.h"
#include "ModuleSceneManager.h"

ModuleSceneManager::ModuleSceneManager()
{}

ModuleSceneManager::~ModuleSceneManager()
{}

bool ModuleSceneManager::CleanUp()
{
	if (mCurrentScene)
	{
		delete mCurrentScene;
		mCurrentScene = nullptr;
	}

	return true;
}

bool ModuleSceneManager::Init()
{
	mCurrentScene = new GameScene();
	mCurrentScene->Init();
	return true;
}

bool ModuleSceneManager::Update()
{
	mCurrentScene->Update();

	return true;
}
