/*
 * Main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: adolfo
 */

#include "GameManager.h"
#include "Globals.h"
#include <iostream>

GameManager *game = nullptr;

int main(int argc, char* args[])
{
	int ret = EXIT_SUCCESS;
	std::cout << "*** Game Creation\n";
	game = new GameManager();
	MainState state = MainState::MAIN_INIT;

	while (state != MainState::MAIN_EXIT)
	{
		switch(state)
		{
		case MAIN_INIT:
			std::cout << "*** Game Initialization\n";
			if(!game->Init())
			{
				std::cout << "Failed to initialize game!\n";
				ret = EXIT_FAILURE;
				state = MainState::MAIN_EXIT;
			}
			else
			{
				state = MainState::MAIN_UPDATE;
			}
			break;
		case MainState::MAIN_UPDATE:
			if(!game->Update())
			{
				state = MainState::MAIN_CLEANUP;
			}
			break;
		case MainState::MAIN_CLEANUP:
			std::cout << "*** Game Clean Up\n";
			if(!game->CleanUp())
			{
				std::cout << "Failed to release game resources!\n";
				ret = EXIT_FAILURE;

			}
			state = MainState::MAIN_EXIT;
			break;
		case MainState::MAIN_EXIT:
			return ret;
		}
	}
}

