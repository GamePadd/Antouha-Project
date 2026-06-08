#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <iostream>
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/Resources/Texture.h"
#include "../Event/EventBus.h"

#include "Events.h"

constexpr int kScreenWidth{ 640 };
constexpr int kScreenHeight{ 480 };

SDL_Window* gWindow{ nullptr };
SDL_Renderer* gRenderer{ nullptr };

bool initSDL() {
	bool success{ true };
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		if (gWindow = SDL_CreateWindow("BulbaOral", kScreenWidth, kScreenHeight, 0); gWindow == nullptr) {
			SDL_Log("Window could not created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, 0);
		}
	}

	return success;
}

void close() {
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	int exitCode{ 0 };
	if (initSDL() == false) {
		SDL_Log("Can't init a program!\n");
		exitCode = 1;
	}
	else {
		Ant::ResourceManager<Ant::Texture>* TextureManager = new Ant::ResourceManager<Ant::Texture>();
		TextureManager->load("bulba", gRenderer, "bulba.jpg");

		//Event bus

		Ant::EventBus* eventBus = new Ant::EventBus();
		eventBus->subscribe<Ant::TestEvent>([](const Ant::TestEvent& e) {
			SDL_Log("Test event worked per frame !: value = %d", e.value);
			});
		//Game cycle

		bool quit{ false };

		SDL_Event e;
		SDL_zero(e);

		Ant::Texture* bulb = TextureManager->get("bulba");

		while (!quit) {
			SDL_Log("------------------------");
			//Poll events
			while (SDL_PollEvent(&e) == true) {
				if (e.type == SDL_EVENT_QUIT) {
					quit = true;
				}
			}

			//Update logic

			//test event emit

			eventBus->queueEvent<Ant::TestEvent>(Ant::TestEvent{ 5 });
			eventBus->queueEvent<Ant::TestEvent>(Ant::TestEvent{ 5 });

			eventBus->process();

			//Render
			SDL_RenderClear(gRenderer);

			if (bulb != nullptr) { bulb->render(35.5f, 35.5f, 45.0f, 45.0f); }
			if (bulb != nullptr) { bulb->render(35.5f, 75.0f, 250.0f, 55.0f); }

			SDL_RenderPresent(gRenderer);
		}
	}

	close();
	return exitCode;
}
