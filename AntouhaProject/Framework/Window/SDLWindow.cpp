#include "SDLWindow.h"
#include "../Event/Events.h"

namespace Ant {
	bool SDLWindow::init() {
		bool success{ true };

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			if (window = SDL_CreateWindow(windowName, size.x, size.y, 0); window == nullptr) {
				SDL_Log("Window could not created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				renderer = SDL_CreateRenderer(window, NULL);
				SDL_Log("SDL Window initialized!\n");

				if (TTF_Init() == false) {
					SDL_Log("Can't init a SDL_ttf! SDL_ttf error: %s\n", SDL_GetError());
					success = false;
				}
			}
		}

		isInitialized = success;
		return success;
	}

	void SDLWindow::swapBuffers() {
		SDL_RenderPresent(renderer);
	}

	void SDLWindow::pollEvents() {
		SDL_Event e;
		SDL_zero(e);

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_KEY_DOWN ||
				e.type == SDL_EVENT_KEY_UP ||
				e.type == SDL_EVENT_MOUSE_MOTION ||
				e.type == SDL_EVENT_MOUSE_BUTTON_DOWN ||
				e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
				eventBus->fire<PollEvent>(PollEvent{ e });
			}

			switch (e.type) {
				case SDL_EVENT_QUIT:
					if (onClose != nullptr) onClose();
					break;
			}
		}
	}

	SDLWindow::~SDLWindow() {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;

		SDL_DestroyWindow(window);
		window = nullptr;

		SDL_Quit();
	}
}