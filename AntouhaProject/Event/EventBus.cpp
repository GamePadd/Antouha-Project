#include "EventBus.h"

namespace Ant {
	void EventBus::process() {
		while (!eventQueue.empty()) {
			auto& eventPtr = eventQueue.front();
			size_t id = typeid(*eventPtr).hash_code();

			if (handlers.count(id)) {
				for (auto& handler : handlers[id]) {
					handler(*eventPtr);
				}
			}

			eventQueue.pop();
		}
	}
}