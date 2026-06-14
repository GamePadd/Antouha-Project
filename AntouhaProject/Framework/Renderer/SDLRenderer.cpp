#include "SDLRenderer.h"
#include <algorithm>
namespace Ant {
	void SDLRenderer::Clear() {
		SDL_RenderClear(renderer);
	}

	void SDLRenderer::QueueTexture(const Texture* texture, const Vec2f &pos, const Vec2f &size, int layer) {
		if (layer < 0 || layer > MAX_LAYERS) { return; }
		layers[layer].push_back(RenderLayerElement{ (SDL_Texture*)texture->get(), pos, size});
	}

	void SDLRenderer::QueueText(const Text* text, const Vec2f& pos, const Vec2f& size, int layer) {
		if (layer < 0 || layer > MAX_LAYERS) { return; }
		layers[layer].push_back(RenderLayerElement{ (SDL_Texture*)text->get(), pos, size});
	}

	void SDLRenderer::RenderAll() {
		float scaleX = (float)context->getWidth() / virtualSize.x;
		float scaleY = (float)context->getHeight() / virtualSize.y;

		for (int i = 0; i < MAX_LAYERS; i++) {
			if (layers[i].empty()) { continue; }
			for (auto& it : layers[i]) {
				//SDL_FRect dstRect{ it.pos.x - (it.size.x/2.0f), it.pos.y - (it.size.y / 2.0f), it.size.x, it.size.y };
				SDL_FRect dstRect{ 
					it.pos.x* scaleX - (it.size.x* scaleX / 2.0f),
					it.pos.y* scaleY - (it.size.y* scaleY / 2.0f),
					it.size.x* scaleX, it.size.y* scaleY
				};

				SDL_RenderTexture(renderer, it.texture, nullptr, &dstRect);
			}
			layers[i].clear();
		}
	}
}