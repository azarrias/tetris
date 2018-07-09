/*
* GameScene.h
*
*  Created on: Jul 09, 2018
*      Author: adolfo
*/

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "IScene.h"
#include <SDL2/SDL.h>
#include "SimpleTimer.h"
#include <vector>

class Tetromino;

class GameScene : public IScene
{
public:
	GameScene();

	void CheckForLines();
	bool CleanUp() override;
	bool Init() override;
	void LockCurrentTetromino();
	void SpawnTetromino();
	bool Update() override;

	int mPlayerOneScore = 0;
	int mPlayerTwoScore = 0;
	
	std::vector<std::vector<int>> mBoard;
	SDL_Rect mBoardRect;
	Tetromino *mPlayingTetromino;
	SimpleTimer mTimer;
};

#endif // GAMESCENE_H_