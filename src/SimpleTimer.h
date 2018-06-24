/*
* SimpleTimer.h
*
*  Created on: June 24, 2018
*      Author: adolfo
*/

#ifndef SIMPLETIMER_H_
#define SIMPLETIMER_H_

#include <SDL2/SDL.h>

class SimpleTimer
{
public:
	SimpleTimer()
	: mStart(SDL_GetTicks())
	{}

	Uint32 getDelta() const {
		return SDL_GetTicks() - mStart;
	}

	void reset()
	{
		mStart = SDL_GetTicks();
	}

private:
	Uint32 mStart;
};

#endif // SIMPLETIMER_H_
