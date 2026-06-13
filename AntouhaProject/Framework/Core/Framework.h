#pragma once

#include "../Event/EventBus.h"
#include "../Renderer/IRenderer.h"
#include "../Window/IWindow.h"
#include "../ResourceManager/ResourceManager.h"
#include  "../ResourceManager/Resources/Texture.h"
#include "../ResourceManager/Resources/Text.h"
#include "IGameLogic.h"
#include "../ScreenManager/ScreenManager.h"
#include "../InputService/InputService.h"

namespace Ant {
	enum class WindowRenderer {SDL};
	enum class RendererAPI {SDL};

	struct FrameworkConfig {
		WindowRenderer window;
		RendererAPI renderer;
		const char* title;
		int width;
		int height;

		FrameworkConfig(
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

	class Framework {
		private:
			IWindow* window;
			IRenderer* renderer;

			ResourceManager<Texture> textureManager;
			ResourceManager<Text> textManager;

			FrameworkConfig config;

			EventBus eventBus;

			InputService* inputService;

			//Game

			IGameLogic* game;
			ScreenManager screenManager;

			void CreateWindow();
			void CreateRenderer();

		public:
			Framework(const FrameworkConfig&, IGameLogic*);
			~Framework();
			void run();
	};
}