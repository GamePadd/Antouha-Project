#pragma once

#include "../Window/IWindow.h"

namespace Ant {
	class Renderer {
		private:
			IWindow* context;
		public:
			Renderer(IWindow* _context) : context(_context) {}

			void render();
	};
}