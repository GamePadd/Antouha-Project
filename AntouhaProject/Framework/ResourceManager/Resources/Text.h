#pragma once

#include "../IResource.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

namespace Ant {
	class Text : public IResource {
		private:
			SDL_Texture* textTexture;
			TTF_Font* font;
			SDL_Renderer* renderer;

			std::string fontPath;

			std::string text;
			SDL_Color textColor;

			int width;
			int height;

			float size;
		public:
			//TODO: мб тут потом сделай систему чтоб оно блять не загружало даже если ошибка будет, защиту продумай в будущем еблана кусок

			Text(SDL_Renderer* _renderer, std::string _text, SDL_Color _textColor, std::string _fontPath) : renderer(_renderer),
			fontPath(_fontPath), text(_text), textColor(_textColor), size(64) {
				load();
			}

			bool load() override;
			bool isLoaded() override { return textTexture != nullptr; }
			void* get() const override { return textTexture; }
			float* getSize();

			void setFont(std::string path, int size);
			void setSize(int size);
			bool updateText(std::string text, int size, SDL_Color textColor = SDL_Color(255, 255, 255, 255));
			void free();

			int getWidth() { return width; }
			int getHeight() { return height; }
	};
}