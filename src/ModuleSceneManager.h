/*
 * ModuleScene.h
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#ifndef MODULESCENEMANAGER_H_
#define MODULESCENEMANAGER_H_

#include "IScene.h"
#include "Module.h"
#include <SDL2/SDL.h>
#include "SimpleTimer.h"
#include <vector>

class Tetromino;

class ModuleSceneManager : public Module
{
public:
	ModuleSceneManager();
	~ModuleSceneManager();

	bool CleanUp();
	IScene* CreateScene(SceneType type);
	bool Init();
	bool Update();

/*	void CheckForLines();
	bool CleanUp();
	bool Init();
	void LockCurrentTetromino();
	void SpawnTetromino();
	bool Update(); 

	int mPlayerOneScore = 0;
	int mPlayerTwoScore = 0;*/

/*	std::vector<std::vector<int>> mBoard;
	SDL_Rect mBoardRect;
	Tetromino *mPlayingTetromino;
	SimpleTimer mTimer;*/
	IScene *mCurrentScene;
};

#endif /* MODULESCENEMANAGER_H_ */
