#include "SDLWindow.h"

namespace Ant {
	bool SDLWindow::init() {
		bool success{ true };

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			if (window = SDL_CreateWindow("BulbaOral", width, height, 0); window == nullptr) {
				SDL_Log("Window could not created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				renderer = SDL_CreateRenderer(window, 0);
			}
		}

		isInitialized = success;
		return success;
	}

	SDLWindow::~SDLWindow() {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;

		SDL_DestroyWindow(window);
		window = nullptr;

		SDL_Quit();
	}
}