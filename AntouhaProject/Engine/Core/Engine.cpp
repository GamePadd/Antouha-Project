#include "Engine.h"
#include "../Window/SDLWindow.h"
#include "../Renderer/SDLRenderer.h"
#include "../Event/Events.h"

namespace Ant {
	Engine::Engine(const EngineConfig& cfg) : config(cfg) {
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
		bool quit{ false };

		eventBus.subscribe<QuitEvent>([&](const QuitEvent& e) {
			quit = true;
			SDL_Log("CLOSE EVENT WORKED!\n");
		});

		SDL_Event e;
		SDL_zero(e);

		while (!quit) {
			//Process events
			window->pollEvents();
			eventBus.process();

			//Render screen
			window->swapBuffers();
		}
	}
}