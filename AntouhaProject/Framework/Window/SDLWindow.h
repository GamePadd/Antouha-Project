#pragma once

#include "IWindow.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "../Event/EventBus.h"

namespace Ant {
	class SDLWindow : public IWindow {
		private:
			SDL_Window* window;
			SDL_Renderer* renderer;

			const char* windowName;

			int width;
			int height;

			bool isInitialized;

			CloseCallback onClose;

			EventBus* eventBus;

			//friend class SDLRenderer;

		public:
			SDLWindow(const char* _windowName, int _width, int _height, EventBus* _eventBus) :
				windowName(_windowName),
				width(_width),
				height(_height),
				window{ nullptr },
				renderer{ nullptr },
				eventBus {_eventBus},
				isInitialized{ false } {}

			bool init() override;

			//Getters

			int getWidth() const override { return width; }
			int getHeight() const override { return height; }
			void* getNativeHandle() const override { return renderer; }

			void swapBuffers() override;
			void pollEvents() override;

			void setOnClose(CloseCallback callback) { onClose = callback; }

			~SDLWindow();
	};
}