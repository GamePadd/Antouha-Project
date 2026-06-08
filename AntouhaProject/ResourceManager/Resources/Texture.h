#pragma once

#include "../IResource.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Ant {
	class Texture : public IResource {
		private:
			SDL_Texture* texture;

			int width;
			int height;

			SDL_Renderer* renderer;
			std::string path;
		public:
			Texture(SDL_Renderer* _renderer, const char* _path) : 
				renderer(std::move(_renderer)), 
				path(std::move(_path)),
				texture{ nullptr },
				width{ 0 },
				height{ 0 } {}

			bool load() override;
			bool isLoaded() override { return texture != nullptr; };

			void free() override;

			void render(float x, float y, float width = 25, float height = 25);

			int getWidth() { return width; }
			int getHeight() { return height; }
	};
}