#pragma once

#include "../Engine/EngineH.h"

namespace Ant {
	struct TestEvent : public IEvent {
		int value;

		TestEvent(int a) : value(a) {}
	};
}