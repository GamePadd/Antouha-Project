#pragma once

#include "../Event/EventBus.h"
#include "../Renderer/IRenderer.h"
#include "../Window/IWindow.h"
#include "../ResourceManager/ResourceManager.h"
#include  "../ResourceManager/Resources/Texture.h"

namespace Ant {
	enum class WindowRenderer {
		SDL
	};
	
	enum class RendererAPI {
		SDL
	};

	struct EngineConfig {
		WindowRenderer window;
		RendererAPI renderer;
		const char* title;
		int width;
		int height;

		EngineConfig(
			const WindowRenderer& _window,
			const RendererAPI& _renderer, 
			const char* _title = "Default",
			const int& _width = 640,
			const int& _height = 480
		) :
			window(_window),
			renderer(_renderer),
			title(_title),
			width(_width),
			height(_height) {}
	};

	class Engine {
		private:
			IWindow* window;
			IRenderer* renderer;

			ResourceManager<Texture> textureManager;

			EngineConfig config;

			EventBus eventBus;

			void CreateWindow();
			void CreateRenderer();

		public:
			Engine(const EngineConfig&);
			~Engine();
			void run();
	};
}