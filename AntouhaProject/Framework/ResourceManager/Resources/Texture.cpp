#include "Texture.h"

namespace Ant {
	bool Texture::load() {
		bool success = true;

		free();

		if (SDL_Surface* loadedSurface = IMG_Load(path.c_str()); loadedSurface == nullptr) {
			SDL_Log("Can't load texture %s! SDL_Image error: %s\n", path.c_str(), SDL_GetError());
			success = false;
		}
		else {
			if (texture = SDL_CreateTextureFromSurface(renderer, loadedSurface); texture == nullptr) {
				SDL_Log("Can't create texture from loaded image! SDL error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				width = loadedSurface->w;
				height = loadedSurface->h;

				SDL_Log("Successfully loaded texture %s\n", path.c_str());
			}

			SDL_DestroySurface(loadedSurface);
		}

		return success;
	}

	void Texture::free() {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		width = 0;
		height = 0;
	}
}