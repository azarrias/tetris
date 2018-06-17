/*
 * GameManager.h
 *
 *  Created on: May 26, 2018
 *      Author: adolfo
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Globals.h"
#include <list>
#include "Module.h"

class ModuleEntityManager;
class ModuleGUI;
class ModuleInput;
class ModuleRender;
class ModuleScene;
class ModuleWindow;

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool CleanUp();
	bool Init();
	bool Update();

	ModuleEntityManager *mEntities = nullptr;
	ModuleGUI *mGUI = nullptr;
	ModuleInput *mInput = nullptr;
	ModuleRender *mRenderer = nullptr;
	ModuleScene *mScene = nullptr;
	ModuleWindow *mWindow = nullptr;
private:
	std::list<Module*> mModules;
};

#endif /* GAMEMANAGER_H_ */
