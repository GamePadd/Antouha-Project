#include "InputService.h"
#include <algorithm>

namespace Ant {
	void InputService::beginFrame() {
		for (auto it : keyCodes) {
			previousState[it] = currentState[it];
		}
	}

	bool InputService::isKeyPressed(unsigned int key) {
		//SDL_Log("key pressed test key is %d, current state is %d, previous is %d", key, currentState[key], previousState[key]);
		return currentState[key] && !previousState[key];
	}

	bool InputService::isKeyReleased(unsigned int key) {
		return !currentState[key] && previousState[key];
	}

	bool InputService::isKeyDown(unsigned int key) {
		return currentState[key];
	}

	void InputService::addTrackingKey(KeyCode code) {
		auto it = std::find(keyCodes.begin(), keyCodes.end(), code);
		if (it == keyCodes.end()) { keyCodes.push_back(code); SDL_Log("Add key %d to tracking", code);}
	}

	//TODO: Как-то в будущем изьебнись и сделай тут универсальную обёртку не только под SDL

	void InputService::updateInfo(SDL_Event &e) {
		for (auto it : keyCodes) {
			if (e.type == SDL_EVENT_KEY_DOWN || e.type == SDL_EVENT_KEY_UP) {
				auto itt = std::find(keyCodes.begin(), keyCodes.end(), e.key.key);
				if (itt != keyCodes.end()) {
					currentState[it] = (e.type == SDL_EVENT_KEY_DOWN);
					break;
				}
			}
		}
	}

	void InputService::removeFromTraking(KeyCode code) {
		auto it = std::find(keyCodes.begin(), keyCodes.end(), code);
		if (it != keyCodes.end()) { keyCodes.erase(it); }
	}
}