#include "Engine.h"
#include "../Window/SDLWindow.h"
#include "../Renderer/SDLRenderer.h"
#include "../Event/Events.h"
#include "GameServices.h"
#include <chrono>

namespace Ant {
	Engine::Engine(const EngineConfig& cfg, IGameLogic* _game) : config(cfg), game(_game) {
		CreateWindow();
		CreateRenderer();

		window->setOnClose([&]() {
			eventBus.queueEvent<QuitEvent>(QuitEvent());
		});
	}

	Engine::~Engine() {
		delete window;
		delete renderer;
	}

	void Engine::CreateWindow() {
		switch (config.window) {
			case WindowRenderer::SDL:
				window = new SDLWindow(config.title, config.width, config.height);
				break;
		}

		window->init();
	}

	void Engine::CreateRenderer() {
		switch (config.renderer) {
			case RendererAPI::SDL:
				renderer = new SDLRenderer(window);
				break;
		}
	}

	void Engine::run() {
		//Game init
		GameServices services;
		services.window = window;
		services.renderer = renderer;
		services.eventBus = &eventBus;
		services.textures = &textureManager;

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

			game->update(dt);

			//Render screen
			game->render();
			window->swapBuffers();
		}

		game->quit();
	}
}