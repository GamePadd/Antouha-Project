#pragma once

#include "../ResourceManager/Resources/Texture.h"
#include "../Math/Math.h"

namespace Ant {
	struct RenderLayerElement {
		const Texture* texture;
		Vec2f pos;
		Vec2f size;
	};

	class IRenderer {
		private:
			virtual void RenderAll() = 0;

			friend class Framework;
		public:
			virtual ~IRenderer() = default;

			virtual void Clear() = 0;
			virtual void QueueTexture(const Texture* texture, Vec2f pos, Vec2f size, int layer) = 0;
	};
}