/*
 * ModuleWindow.cpp
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#include "Globals.h"
#include <iostream>
#include "ModuleWindow.h"
#include <SDL2/SDL.h>

ModuleWindow::ModuleWindow()
{}

ModuleWindow::~ModuleWindow()
{}

bool ModuleWindow::CleanUp()
{
	std::cout << "Destroying SDL window and quitting SDL systems\n";
	if(mWindow)
	{
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
	}

	SDL_Quit();
	return true;
}

bool ModuleWindow::Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		return false;
	}

	mWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(!mWindow)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
		return false;
	}

	return true;
}
