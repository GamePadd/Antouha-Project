#pragma once

#include "../Framework/FrameworkH.h"

class TestScreen : public Ant::IScreen {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::EventBus* events;
		Ant::ScreenManager* screens;

		//Textures

		Ant::Texture* bulba = nullptr;
		Ant::Vec2f bulbaPos = Ant::Vec2f{ 125.0f,125.0f };
		Ant::Vec2f bulbaSize = Ant::Vec2f{ 255.0f,255.0f };

	public:
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;

			//Load textures

			textures->load("bulba", (SDL_Renderer*)window->getNativeHandle(), "bulba.jpg");
			bulba = textures->get("bulba");
		}

		void onUpdate(float dt) override {

		}

		void onRender() override {
			for (int i = 0; i < 2000; i++) {
				renderer->QueueTexture(bulba, bulbaPos, bulbaSize, 1);
			}
		}

		void onClose() override {

		}
};

class TestGame : public Ant::IGameLogic {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::EventBus* events;
		Ant::ScreenManager* screens;

	public:
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;

			Ant::IScreen* mainScr = new TestScreen();
			mainScr->init(services);
			screens->pushScreen(mainScr);
		}

		void onUpdate(float dt) override {

		}

		void onQuit() override {

		}
};
