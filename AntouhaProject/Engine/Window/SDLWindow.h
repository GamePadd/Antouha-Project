#pragma once

#include "IWindow.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Ant {
	class SDLWindow : public IWindow {
		private:
			SDL_Window* window;
			SDL_Renderer* renderer;

			int width;
			int height;

			bool isInitialized;

		public:
			SDLWindow(const char* windowName = "Default", int _width = 640, int _height = 480) :
				width(_width),
				height(_height),
				window{ nullptr },
				renderer{ nullptr },
				isInitialized{ false } {}

			bool init() override;

			//Getters

			int getWidth() const override { return width; }
			int getHeight() const override { return height; }

			~SDLWindow();
	};
}