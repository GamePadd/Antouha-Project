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
		Vec2i virtualSize;
		Vec2i actualSize;

		FrameworkConfig(
			const WindowRenderer& _window,
			const RendererAPI& _renderer, 
			const char* _title = "Default",
			const Vec2i& _vs = Vec2i(640,480),
			const Vec2i& _as = Vec2i(640, 480)
		) :
			window(_window),
			renderer(_renderer),
			title(_title),
			virtualSize(_vs),
			actualSize(_as) {}
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