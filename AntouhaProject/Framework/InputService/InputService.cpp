#include "InputService.h"
#include <algorithm>

namespace Ant {
	void InputService::beginFrame() {
		for (auto& it : mouseState) {
			it.second.previousState = it.second.currentState;
		}

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

	void InputService::RegisterKey(KeyCode code) {
		auto it = std::find(keyCodes.begin(), keyCodes.end(), code);
		if (it == keyCodes.end()) { keyCodes.push_back(code); SDL_Log("Added key %d to tracking", code);}
	}

	//TODO: Как-то в будущем изьебнись и сделай тут универсальную обёртку не только под SDL

	void InputService::updateInfo(SDL_Event &e) {
		SDL_GetMouseState(&mouseX, &mouseY);

		if (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN || e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
			mouseState[e.button.button].currentState = (e.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
		}

		if (e.type == SDL_EVENT_KEY_DOWN || e.type == SDL_EVENT_KEY_UP) {
			auto itt = std::find(keyCodes.begin(), keyCodes.end(), e.key.key);
			if (itt != keyCodes.end()) {
				currentState[*itt] = (e.type == SDL_EVENT_KEY_DOWN);
			}
		}
	}

	void InputService::Remove(KeyCode code) {
		auto it = std::find(keyCodes.begin(), keyCodes.end(), code);
		if (it != keyCodes.end()) { keyCodes.erase(it); }
	}

	bool InputService::isMousePressed(Uint8 button) {
		return mouseState[button].currentState && !mouseState[button].previousState;
	}

	bool InputService::isMouseReleased(Uint8 button) {
		return !mouseState[button].currentState && mouseState[button].previousState;
	}

	bool InputService::isMouseDown(Uint8 button) {
		return mouseState[button].currentState;
	}
}