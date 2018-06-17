/*
 * ModuleInput.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULEINPUT_H_
#define MODULEINPUT_H_

#include "Globals.h"
#include "Module.h"

class ModuleInput : public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool CleanUp();
	bool Init();
	bool Update();
};

#endif /* MODULEINPUT_H_ */
