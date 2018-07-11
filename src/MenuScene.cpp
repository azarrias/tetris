/*
* MenuScene.cpp
*
*  Created on: Jul 09, 2018
*      Author: adolfo
*/

#include "Globals.h"
#include <iostream>
#include "MenuScene.h"

MenuScene::MenuScene(char *title, std::vector<std::string> &options)
: IScene(SceneType::MENU_SCENE), mTitle(title), mOptions(options)
{
}

bool MenuScene::CleanUp() 
{
	TTF_CloseFont(mFont);
	TTF_Quit();

	return true;
}

bool MenuScene::Init() 
{
	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";
		return false;
	}

	mFont = TTF_OpenFont(FONT_PATH_NORMAL, FONT_SIZE);
	SDL_Color color = { 255, 255, 255 };

	SDL_Surface *surface = TTF_RenderText_Solid(mFont, mTitle, color);

	return true;
}

bool MenuScene::Update()
{
	return true;
}