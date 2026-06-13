#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <vector>
#include "../Event/EventBus.h"
#include "../Event/Events.h"

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

			KeyCodesList keyCodes;

			std::unordered_map<KeyCode, bool> currentState;
			std::unordered_map<KeyCode, bool> previousState;
			std::unordered_map<Uint8, MouseButton> mouseState;
			//Mouse

			float mouseX;
			float mouseY;

			void updateInfo(SDL_Event &e);
			void beginFrame();

			friend class Framework;
		public:
			InputService(EventBus* _eventBus, const KeyCodesList& _keys = KeyCodesList()) : keyCodes{ _keys }, 
				eventBus{ _eventBus }, 
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

			float getMouseX() const { return mouseX; }
			float getMouseY() const { return mouseY; }

			bool isMousePressed(Uint8 button);
			bool isMouseReleased(Uint8 button);
			bool isMouseDown(Uint8 button);
	};
}