#pragma once

#include "IWindow.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../Event/EventBus.h"
#include "../Math/Math.h"

namespace Ant {
	class SDLWindow : public IWindow {
		private:
			SDL_Window* window;
			SDL_Renderer* renderer;

			const char* windowName;

			Vec2i size;

			bool isInitialized;

			CloseCallback onClose;

			EventBus* eventBus;

			//friend class SDLRenderer;

		public:
			SDLWindow(const char* _windowName, Vec2i _size, EventBus* _eventBus) :
				windowName(_windowName),
				size(_size),
				window{ nullptr },
				renderer{ nullptr },
				eventBus {_eventBus},
				isInitialized{ false } {}

			bool init() override;

			//Getters

			int getWidth() const override { return size.x; }
			int getHeight() const override { return size.y; }
			void* getNativeHandle() const override { return renderer; }

			void swapBuffers() override;
			void pollEvents() override;

			void setOnClose(CloseCallback callback) { onClose = callback; }

			~SDLWindow();
	};
}