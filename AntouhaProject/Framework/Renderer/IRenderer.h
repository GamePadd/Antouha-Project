#pragma once

#include "../ResourceManager/Resources/Texture.h"
#include "../ResourceManager/Resources/Text.h"
#include "../Math/Math.h"

namespace Ant {
	struct RenderLayerElement {
		SDL_Texture* texture;
		Vec2f pos;
		Vec2f size;

		Uint8 alpha;
	};

	class IRenderer {
		private:
			virtual void RenderAll() = 0;

			friend class Framework;
		public:
			virtual ~IRenderer() = default;

			virtual void Clear() = 0;
			virtual void QueueTexture(const Texture* texture, const Vec2f& pos, const Vec2f& size, int layer, Uint8 alpha = 255) = 0;
			virtual void QueueText(const Text* text, const Vec2f& pos, const Vec2f& size, int layer, Uint8 alpha = 255) = 0;
	};
}