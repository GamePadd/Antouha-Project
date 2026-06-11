#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <vector>
#include "../Event/EventBus.h"
#include "../Event/Events.h"

namespace Ant {
	using KeyCode = unsigned int;
	using KeyCodesList = std::vector<KeyCode>;

	class InputService {
		private:
			EventBus* eventBus;

			KeyCodesList keyCodes;

			std::unordered_map<KeyCode, bool> currentState;
			std::unordered_map<KeyCode, bool> previousState;

			void updateInfo(SDL_Event &e);
			void beginFrame();

			friend class Framework;
		public:
			InputService(EventBus* _eventBus, const KeyCodesList& _keys = KeyCodesList()) : keyCodes{ _keys }, eventBus{ _eventBus } {
				eventBus->subscribe<PollEvent>([&](const PollEvent& e) {
					updateInfo(e.e);
				});
			}

			void addTrackingKey(KeyCode code);
			void removeFromTraking(KeyCode code);

			bool isKeyPressed(unsigned int key);
			bool isKeyReleased(unsigned int key);
			bool isKeyDown(unsigned int key);
	};
}