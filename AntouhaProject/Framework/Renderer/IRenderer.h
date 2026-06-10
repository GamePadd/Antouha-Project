#pragma once

#include "../ResourceManager/Resources/Texture.h"

namespace Ant {
	class IRenderer {
		private:
			virtual void RenderAll() = 0;

		public:
			virtual ~IRenderer() = default;

			virtual void Clear() = 0;
			virtual void QueueTexture(const Texture& texture, int layer) = 0;
	};
}