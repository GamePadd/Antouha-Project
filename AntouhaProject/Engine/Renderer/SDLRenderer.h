#pragma once

#include "../Window/IWindow.h"
#include "IRenderer.h"

namespace Ant {
	class SDLRenderer : IRenderer {
		private:
			IWindow* context;
		public:
			SDLRenderer(IWindow* _context) : context(_context) {}

			void render();
	};
}