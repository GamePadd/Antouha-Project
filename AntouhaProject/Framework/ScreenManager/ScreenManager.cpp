#include "ScreenManager.h"

namespace Ant {
	ScreenManager::~ScreenManager() {
		while (!screenStack.empty()) {
			screenStack.pop();
		}
	}

	void ScreenManager::pushScreen(IScreen* screen) {
		screenStack.push(screen);
	}

	void ScreenManager::popScreen() {
		screenStack.pop();
	}
}