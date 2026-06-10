#include "Framework.h"
#include "../Window/SDLWindow.h"
#include "../Renderer/SDLRenderer.h"
#include "../Event/Events.h"
#include "GameServices.h"
#include <chrono>

namespace Ant {
	Framework::Framework(const FrameworkConfig& cfg, IGameLogic* _game) : config(cfg), game(_game) {
		CreateWindow();
		CreateRenderer();

		window->setOnClose([&]() {
			eventBus.queueEvent<QuitEvent>(QuitEvent());
		});
	}

	Framework::~Framework() {
		delete window;
		delete renderer;
		delete game;
	}

	void Framework::CreateWindow() {
		switch (config.window) {
			case WindowRenderer::SDL:
				window = new SDLWindow(config.title, config.width, config.height);
				break;
		}

		window->init();
	}

	void Framework::CreateRenderer() {
		switch (config.renderer) {
			case RendererAPI::SDL:
				renderer = new SDLRenderer(window);
				break;
		}
	}

	void Framework::run() {
		//Game init
		GameServices services;
		services.window = window;
		services.renderer = renderer;
		services.eventBus = &eventBus;
		services.textures = &textureManager;
		services.screens = &screenManager;

		game->init(services);

		bool quit{ false };

		eventBus.subscribe<QuitEvent>([&](const QuitEvent& e) {
			quit = true;
			SDL_Log("CLOSE EVENT WORKED!\n");
		});

		SDL_Event e;
		SDL_zero(e);

		auto lastTime = std::chrono::high_resolution_clock::now();

		while (!quit) {
			//dt
			auto currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> dtDuration = currentTime - lastTime;
			float dt = dtDuration.count();
			lastTime = currentTime;

			//Process events
			window->pollEvents();
			eventBus.process();

			//Update logic

			game->onUpdate(dt);

			if (screenManager.getScreenCount() != 0) {
				IScreen* scr = screenManager.getTop();
				scr->onUpdate(dt);
				scr->onRender();
			}

			renderer->RenderAll();
			window->swapBuffers();
		}

		game->onQuit();
	}
}