/*
 * Module.h
 *
 *  Created on: May 27, 2018
 *      Author: adolfo
 */

#ifndef MODULE_H_
#define MODULE_H_

#include "Globals.h"

class Module
{
public:
	Module()
	{}

	virtual ~Module()
	{}

	virtual bool Init()
	{
		return true;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual bool Update()
	{
		return true;
	}

	virtual bool CleanUp()
	{
		return true;
	}
};



#endif /* MODULE_H_ */
