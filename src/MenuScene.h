/*
* MenuScene.h
*
*  Created on: Jul 09, 2018
*      Author: adolfo
*/

#ifndef MENUSCENE_H_
#define MENUSCENE_H_

#include "IScene.h"
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

class MenuScene : public IScene
{
public:
	MenuScene(char *title, std::vector<std::string> &options);

	bool CleanUp() override;
	bool Init() override;
	bool Update() override;

	TTF_Font *mFont = nullptr;
	std::vector<std::string> mOptions;
	std::vector<SDL_Texture*> mOptionsTextures;
	char *mTitle;
	SDL_Texture *mTitleTexture;
};

#endif // MENUSCENE_H_