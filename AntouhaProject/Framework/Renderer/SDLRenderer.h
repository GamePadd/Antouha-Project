#pragma once

#include "../Window/IWindow.h"
#include "IRenderer.h"

#define MAX_LAYERS 32

namespace Ant {
	class SDLRenderer : public IRenderer {
		private:
			IWindow* context;
			SDL_Renderer* renderer;

			std::vector<RenderLayerElement> layers[MAX_LAYERS];

			void RenderAll() override;
		public:
			SDLRenderer(IWindow* _context) : context(_context) { renderer = (SDL_Renderer*)context->getNativeHandle(); }

			void Clear() override;
			void QueueTexture(const Texture* texture, Vec2f pos, Vec2f size, int layer) override;
	};
}