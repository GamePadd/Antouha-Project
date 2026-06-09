#pragma once

#include "IInputService.h"

#include <SDL3/SDL.h>

namespace Ant {
	class InputService : public IInputService {
		public:
			bool isKeyPressed() override;
	};
}