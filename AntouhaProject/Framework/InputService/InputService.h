#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <vector>
#include "../Event/EventBus.h"
#include "../Event/Events.h"
#include "../Math/Math.h"
#include "../Window/IWindow.h"

namespace Ant {
	using KeyCode = unsigned int;
	using KeyCodesList = std::vector<KeyCode>;

	struct MouseButton {
		bool currentState;
		bool previousState;
	};

	class InputService {
		private:
			EventBus* eventBus;
			IWindow* context;

			KeyCodesList keyCodes;

			std::unordered_map<KeyCode, bool> currentState;
			std::unordered_map<KeyCode, bool> previousState;
			std::unordered_map<Uint8, MouseButton> mouseState;

			//Mouse

			float mouseX;
			float mouseY;

			Vec2i virtualSize;

			void updateInfo(SDL_Event &e);
			void beginFrame();

			friend class Framework;
		public:
			InputService(EventBus* _eventBus, IWindow* _context, Vec2i vs, const KeyCodesList& _keys = KeyCodesList()) : keyCodes{ _keys },
				eventBus{ _eventBus }, 
				virtualSize(vs),
				context(_context),
				mouseX{ 0.0f },
				mouseY{ 0.0f } {
				//Register mouse

				eventBus->subscribe<PollEvent>([&](const PollEvent& e) {
					updateInfo(e.e);
				});
			}

			void RegisterKey(KeyCode code);

			void Remove(KeyCode code);

			bool isKeyPressed(unsigned int key);
			bool isKeyReleased(unsigned int key);
			bool isKeyDown(unsigned int key);

			float getMouseX() const { 
				float scale = (float)context->getWidth() / virtualSize.x;
				return mouseX / scale;
			}

			float getMouseY() const { 
				float scale = (float)context->getHeight() / virtualSize.y;
				return mouseY / scale; 
			}

			bool isMousePressed(Uint8 button);
			bool isMouseReleased(Uint8 button);
			bool isMouseDown(Uint8 button);
	};
}