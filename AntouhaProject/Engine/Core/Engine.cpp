#include "Engine.h"
#include "../Window/SDLWindow.h"
#include "../Renderer/SDLRenderer.h"

namespace Ant {
	Engine::Engine(const EngineConfig& cfg) : config(cfg) {
		CreateWindow();
		CreateRenderer();
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

		window->setOnClose([&]() {
			quit = true;
			SDL_Log("CLOSE CALLBACK WORKED!\n");
		});

		SDL_Event e;
		SDL_zero(e);

		while (!quit) {
			window->pollEvents();
			window->swapBuffers();
		}
	}
}