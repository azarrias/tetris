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
	Tetromino* CreateTetromino(int xIndex, int yIndex);
	bool Init();
	bool Update();

	std::vector<Tetromino*> mTetrominoes;
	Tetromino *mPlayingTetromino;
};

#endif /* MODULEENTITYMANAGER_H_ */
