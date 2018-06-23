/*
 * ModuleRender.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "GameObject.h"
#include "Globals.h"
#include <iostream>
#include "ModuleEntityManager.h"
//#include "ModuleGUI.h"
#include "ModuleRender.h"
#include "ModuleScene.h"
#include "ModuleWindow.h"
#include <SDL2/SDL.h>
#include <vector>

ModuleRender::ModuleRender()
{}

ModuleRender::~ModuleRender()
{}

bool ModuleRender::CleanUp()
{
	std::cout << "Destroying SDL renderer\n";
	if(mRenderer)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = nullptr;
	}

	return true;
}

/*void ModuleRender::DrawScore(int score, bool isPlayerOne) const
{
	SDL_Texture *texture = game->mGUI->GetTexture(score);
	int textureWidth = 0;
	int textureHeight = 0;

	// TODO - Draw other orders of magnitude
	score = score % 10;

	SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
	SDL_Rect rect = { SCREEN_WIDTH / 2 + SCORE_OFFSET_X, SCORE_OFFSET_Y, textureWidth, textureHeight };

	if(isPlayerOne)
	{
		rect.x = rect.x - 2 * SCORE_OFFSET_X - textureWidth;
	}

	SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
}*/

void ModuleRender::DrawBoard() const
{
	// Set render color to black and render board
	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(mRenderer, &game->mScene->mBoardRect);

	// Render all tetromino squares in the board
	for (size_t i = 0; i < game->mScene->mBoard.size(); ++i)
	{
		for (size_t j = 0; j < game->mScene->mBoard[i].size(); ++j)
		{
			if (game->mScene->mBoard[i][j] != 0)
			{
				SDL_Rect rect;
				rect.x = game->mScene->mBoardRect.x + i * CELL_SIDE_SIZE;
				rect.y = game->mScene->mBoardRect.y + j * CELL_SIDE_SIZE;
				rect.w = CELL_SIDE_SIZE;
				rect.h = CELL_SIDE_SIZE;

				SDL_Color color = Tetromino::GetColor(game->mScene->mBoard[i][j]);
				SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
				SDL_RenderFillRect(mRenderer, &rect);
			}
		}
	}
}

bool ModuleRender::Init()
{
	// Create vsynced renderer for window
	mRenderer = SDL_CreateRenderer(game->mWindow->mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!mRenderer)
	{
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
		return false;
	}

	return true;
}

bool ModuleRender::Update()
{
	// Set background render color to grey and clear window
	SDL_SetRenderDrawColor(mRenderer, 0xA9, 0xA9, 0xA9, 0xFF);
	SDL_RenderClear(mRenderer);

	DrawBoard();
	
	// Set render color to white and render all objects
//	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	// TODO: Draw tetrominos
//	SDL_RenderFillRect(mRenderer, game->mEntities->mPlayerOnePaddle->GetRect());
//	SDL_RenderFillRect(mRenderer, game->mEntities->mPlayerTwoPaddle->GetRect());
//	SDL_RenderFillRect(mRenderer, game->mEntities->mBall->GetRect());

	// Render scores
//	DrawScore(game->mScene->mPlayerOneScore, true);
//	DrawScore(game->mScene->mPlayerTwoScore, false);

	SDL_RenderPresent(mRenderer);

	return true;
}
