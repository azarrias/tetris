/*
 * ModuleInput.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameScene.h"
//#include "GameObject.h"
#include "Globals.h"
//#include "ModuleEntityManager.h"
#include "ModuleInput.h"
#include "ModuleSceneManager.h"
#include <SDL2/SDL.h>
#include "Tetromino.h"

ModuleInput::ModuleInput()
{

}

ModuleInput::~ModuleInput()
{

}

bool ModuleInput::CleanUp()
{
	return true;
}

bool ModuleInput::Init()
{
	return true;
}

bool ModuleInput::Update()
{
	SDL_Event e;

	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
		{
			return false;
		}

		if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			GameScene *gameScene = static_cast<GameScene*>(game->mScene->mCurrentScene);
			Tetromino *playingTetromino = gameScene->mPlayingTetromino;

			switch(e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					return false;
					break;
				// Player 1
				case SDLK_w:
					// Rotate
					playingTetromino->Rotate();
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					// Down
					if (playingTetromino->IsAboveGround(1) && playingTetromino->IsCollisionFree(0, 1))
					{
						playingTetromino->Move(0, 1);
					}
					else
					{
						gameScene->LockCurrentTetromino();
						gameScene->CheckForLines();
						gameScene->SpawnTetromino();
					}
					break;
				case SDLK_a:
					// Left
					if (playingTetromino->IsInbounds(-1) && playingTetromino->IsCollisionFree(-1, 0))
					{
						playingTetromino->Move(-1, 0);
					}
					break;
				case SDLK_d:
					// Right
					if (playingTetromino->IsInbounds(1) && playingTetromino->IsCollisionFree(1, 0))
					{
						playingTetromino->Move(1, 0);
					}
					break;
				// Player 2
				case SDLK_UP:
					// Rotate
					//game->mEntities->mPlayerTwoPaddle->mVelocity.mY -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_DOWN:
					// Down
					//game->mEntities->mPlayerTwoPaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
					break;
			}
		}
		else if(e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_w:
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_UP:
					//game->mEntities->mPlayerTwoPaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_DOWN:
					//game->mEntities->mPlayerTwoPaddle->mVelocity.mY -= PADDLE_VELOCITY_DELTA;
					break;
			}
		}
	}

	return true;
}
