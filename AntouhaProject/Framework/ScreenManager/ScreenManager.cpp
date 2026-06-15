#include "ScreenManager.h"

namespace Ant {
	ScreenManager::~ScreenManager() {
		while (!screenStack.empty()) {
			screenStack.pop();
		}
	}

	void ScreenManager::Process() {
		while (!opQueue.empty()) {
			OperationsPair& element = opQueue.front();
			switch (element.first) {
				case ScreenOpType::Push:
					screenStack.push(std::move(element.second));
					break;
				case ScreenOpType::Pop:
					if (!screenStack.empty()) {
						screenStack.pop();
					}

					break;
			}
			opQueue.pop();
		}
	}

	void ScreenManager::pushScreen(std::unique_ptr<IScreen> screen) {
		opQueue.push(OperationsPair(ScreenOpType::Push, std::move(screen)));
	}

	void ScreenManager::popScreen() {
		opQueue.push(OperationsPair(ScreenOpType::Pop, nullptr));
	}
}