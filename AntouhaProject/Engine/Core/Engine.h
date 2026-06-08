#pragma once

#include "../Event/EventBus.h"
#include "../Renderer/IRenderer.h"
#include "../Window/IWindow.h"
#include "../ResourceManager/ResourceManager.h"
#include  "../ResourceManager/Resources/Texture.h"

namespace Ant {
	class Engine {
		private:
			IWindow* window;
			IRenderer* renderer;

			ResourceManager<Texture> textureManager;

		public:
			void run();
	};
}