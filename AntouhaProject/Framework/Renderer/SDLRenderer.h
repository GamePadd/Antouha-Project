#pragma once

#include "../Window/IWindow.h"
#include "IRenderer.h"

#define MAX_LAYERS 32
#define RESERVE_SPRITES 4096

namespace Ant {
	class SDLRenderer : public IRenderer {
		private:
			IWindow* context;
			SDL_Renderer* renderer;

			Vec2i virtualSize;

			std::vector<RenderLayerElement> layers[MAX_LAYERS];

			void RenderAll() override;
		public:
			SDLRenderer(IWindow* _context, Vec2i vs) : context(_context), virtualSize(vs) {
				renderer = (SDL_Renderer*)context->getNativeHandle(); 
				for (int i = 0; i < MAX_LAYERS; i++) {
					layers[i].reserve(RESERVE_SPRITES);
				}
			}

			void Clear() override;
			void QueueTexture(const Texture* texture, const Vec2f& pos, const Vec2f& size, int layer) override;
			void QueueText(const Text* text, const Vec2f& pos, const Vec2f& size, int layer) override;
	};
}