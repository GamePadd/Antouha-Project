#pragma once

#include "../Framework/FrameworkH.h"


struct Player {
	Ant::Vec2f pos;
	Ant::Vec2f size;

	Ant::Texture* sprite;
};

struct GameContext {
	Player ply;
};

class TestScreen : public Ant::IScreen {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::EventBus* events;
		Ant::ScreenManager* screens;
		Ant::InputService* input;

		GameContext& context;

	public:
		TestScreen(GameContext& _context) : context{_context} {}
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;
			input = services.input;

			//Load textures

			textures->load("bulba", (SDL_Renderer*)window->getNativeHandle(), "bulba.jpg");
			context.ply.sprite = textures->get("bulba");
			context.ply.pos = Ant::Vec2f(25.0f, 25.0f);
			context.ply.size = Ant::Vec2f(55.0f, 55.0f);

			//Input monitor

			input->addTrackingKey(ANT_W);
			input->addTrackingKey(ANT_A);
			input->addTrackingKey(ANT_S);
			input->addTrackingKey(ANT_D);
		}

		void onUpdate(float dt) override {
			context.ply.pos += Ant::Vec2f((input->isKeyDown(ANT_D) + (-input->isKeyDown(ANT_A))) * dt * 228, 0);
			context.ply.pos += Ant::Vec2f(0, (input->isKeyDown(ANT_S) + (-input->isKeyDown(ANT_W))) * dt * 228);
		}

		void onRender() override {
			renderer->QueueTexture(context.ply.sprite, context.ply.pos, context.ply.size, 1);
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
		Ant::InputService* input;

		GameContext context;

	public:
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;
			input = services.input;

			Ant::IScreen* mainScr = new TestScreen(context);
			mainScr->init(services);
			screens->pushScreen(mainScr);
		}

		void onUpdate(float dt) override {

		}

		void onQuit() override {

		}
};
