#include "Text.h"

namespace Ant {
	bool Text::load() {
		free();

		bool success{ true };

		if (font = TTF_OpenFont(fontPath.c_str(), size); font == nullptr) {
			SDL_Log("Couldn't load %s! SDL_ttf error: %s\n", fontPath.c_str(), SDL_GetError());
			success = false;
		}
		else {
			if (updateText(text, size, textColor) == false) {
				SDL_Log("Can't update text texture! SDL_ttf error: %s\n", SDL_GetError());
				success = false;
			}
		}

		return success;
	}

	void Text::free() {
		SDL_DestroyTexture(textTexture);
		textTexture = nullptr;
	}

	void Text::setFont(std::string path, int _size) {
		size = _size;
		if (font = TTF_OpenFont(fontPath.c_str(), size); font == nullptr) {
			SDL_Log("Couldn't load %s! SDL_ttf error: %s\n", fontPath.c_str(), SDL_GetError());
		}
	}

	void Text::setSize(int _size) { 
		updateText(text, _size, textColor);
	}

	float* Text::getSize() { return &size; }

	bool Text::updateText(std::string _text, int _size, SDL_Color color) {
		text = _text;
		textColor = color;
		size = _size;

		free();

		TTF_SetFontSize(font, size);

		if (SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), 0, color); textSurface == nullptr) {
			SDL_Log("Can't render text surface! SDL_ttf error: %s\n", SDL_GetError());
		}
		else {
			if (textTexture = SDL_CreateTextureFromSurface(renderer, textSurface); textTexture == nullptr) {
				SDL_Log("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else {
				width = textSurface->w;
				height = textSurface->h;
			}

			SDL_DestroySurface(textSurface);
		}

		return textTexture != nullptr;
	}
}