#pragma once

#include "../Window/IWindow.h"
#include "IRenderer.h"

namespace Ant {
	class SDLRenderer : public IRenderer {
		private:
			IWindow* context;

			void RenderAll() override;
		public:
			SDLRenderer(IWindow* _context) : context(_context) {}

			void Clear() override;
			void QueueTexture(const Texture& texture, int layer) override;
	};
}