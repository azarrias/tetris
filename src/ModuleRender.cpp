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
	// TODO - This board_rect should be a member of the scene
	SDL_Rect board_rect = { SCREEN_WIDTH / 2 - BOARD_WIDTH / 2, SCREEN_HEIGHT / 2 - BOARD_HEIGHT / 2, BOARD_WIDTH, BOARD_HEIGHT };
	// Set render color to black and render all objects
	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(mRenderer, &board_rect);
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
