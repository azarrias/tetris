/*
 * ModuleWindow.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULEWINDOW_H_
#define MODULEWINDOW_H_

#include "Module.h"

struct SDL_Window;

class ModuleWindow : public Module
{
public:
	ModuleWindow();
	~ModuleWindow();
	bool CleanUp();
	bool Init();

	SDL_Window *mWindow = nullptr;
};

#endif /* MODULEWINDOW_H_ */
