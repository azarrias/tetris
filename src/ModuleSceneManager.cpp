/*
 * ModuleSceneManager.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameScene.h"
#include <iostream>
#include "MenuScene.h"
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

IScene* ModuleSceneManager::CreateScene(SceneType type)
{
	static_assert(SceneType::UNKNOWN == 2, "Warning: Some Scene type is not handled!");
	IScene *s = nullptr;
	switch (type) {
	case SceneType::GAME_SCENE:
		s = new GameScene();
		break;
	case SceneType::MENU_SCENE:
//		s = new MenuScene(char *title, std::vector<std::string> &options);
		break;
	default:
		std::cout << "Error: This scene type does not exist\n";
	}

	return s;
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
