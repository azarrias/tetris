/*
 * ModuleInput.cpp
 *
 *  Created on: May 28, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
//#include "GameObject.h"
#include "Globals.h"
//#include "ModuleEntityManager.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
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
			switch(e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					return false;
					break;
				// Player 1
				case SDLK_w:
					// Rotate
					game->mScene->mPlayingTetromino->Rotate();
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY -= PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_s:
					// Down
					game->mScene->mPlayingTetromino->Move(0, 1);
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_a:
					// Left
					game->mScene->mPlayingTetromino->Move(-1, 0);
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
					break;
				case SDLK_d:
					// Right
					game->mScene->mPlayingTetromino->Move(1, 0);
					//game->mEntities->mPlayerOnePaddle->mVelocity.mY += PADDLE_VELOCITY_DELTA;
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
