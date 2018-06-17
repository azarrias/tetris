/*
 * ModuleEntityManager.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULEENTITYMANAGER_H_
#define MODULEENTITYMANAGER_H_

#include "Globals.h"
#include "Module.h"
#include "Tetromino.h"
#include <vector>

class GameObject;

class ModuleEntityManager : public Module
{
public:
	ModuleEntityManager();
	~ModuleEntityManager();

	bool CleanUp();
	GameObject* CreateGameObject(GameObjectType type, int xPos, int yPos, int width, int height);
	bool Init();
	bool Update();

	Tetromino *mPlayingTetromino;

private:
	std::vector<GameObject*> mEntities;
};

#endif /* MODULEENTITYMANAGER_H_ */
