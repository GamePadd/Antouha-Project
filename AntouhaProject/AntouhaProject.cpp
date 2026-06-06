#include "AntouhaProject.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <string>

constexpr int kScreenWidth{ 640 };
constexpr int kScreenHeight{ 480 };

SDL_Window* gWindow{ nullptr };
SDL_Surface* gScreenSurface{ nullptr };
SDL_Surface* gBulbaOral{ nullptr };

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
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadBulba() {
	bool success{ true };

	std::string imagePath{ "bulba.jpg" };
	if (gBulbaOral = IMG_Load(imagePath.c_str()); gBulbaOral == nullptr) {
		SDL_Log("Can't load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError());
		success = false;
	}

	return success;
}

void close() {
	SDL_DestroySurface(gBulbaOral);
	gBulbaOral = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gScreenSurface = nullptr;

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
		if (loadBulba() == false) {
			SDL_Log("Can't load image!\n");
			exitCode = 2;
		}
		else {
			bool quit{ false };

			SDL_Event e;
			SDL_zero(e);

			while (quit == false) {
				while (SDL_PollEvent(&e) == true) {
					if (e.type == SDL_EVENT_QUIT) {
						quit = true;
					}
				}

				SDL_FillSurfaceRect(gScreenSurface, nullptr, SDL_MapSurfaceRGB(gScreenSurface, 0xFF, 0xFF, 0xFF));
				SDL_BlitSurface(gBulbaOral, nullptr, gScreenSurface, nullptr);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return exitCode;
}
