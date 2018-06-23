/*
 * GameManager.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include <list>
#include "Module.h"
//#include "ModuleGUI.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleScene.h"
#include "ModuleWindow.h"

GameManager::GameManager()
{
//	mModules.push_back(mEntities = new ModuleEntityManager());
	mModules.push_back(mScene = new ModuleScene());
	mModules.push_back(mWindow = new ModuleWindow());
	mModules.push_back(mRenderer = new ModuleRender());
//	mModules.push_back(mGUI = new ModuleGUI());
	mModules.push_back(mInput = new ModuleInput());
}

GameManager::~GameManager()
{
	for (std::list<Module*>::iterator it = mModules.begin(); it != mModules.end(); ++it)
	{
		if(*it)
		{
			delete *it;
			*it = nullptr;
		}
	}
}

bool GameManager::CleanUp()
{
	for (std::list<Module*>::reverse_iterator it = mModules.rbegin(); it != mModules.rend(); ++it)
	{
		if(!(*it)->CleanUp())
		{
			return false;
		}
	}

	return true;
}

bool GameManager::Init()
{
	for (std::list<Module*>::iterator it = mModules.begin(); it != mModules.end(); ++it)
	{
		if(!(*it)->Init())
		{
			return false;
		}
	}

	for (std::list<Module*>::iterator it = mModules.begin(); it != mModules.end(); ++it)
	{
		if(!(*it)->Start())
		{
			return false;
		}
	}

	return true;
}

bool GameManager::Update()
{
	for (std::list<Module*>::iterator it = mModules.begin(); it != mModules.end(); ++it)
	{
		if(!(*it)->Update())
		{
			return false;
		}
	}

	return true;
}
