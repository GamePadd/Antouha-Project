#pragma once

#include "../Event/IEvent.h"

namespace Ant {
	struct TestEvent : public IEvent {
		int value;

		TestEvent(int a) : value(a) {}
	};
}