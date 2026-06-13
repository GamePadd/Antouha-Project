#pragma once

#include "../Framework/FrameworkH.h"

#define MAX_BULLETS 256

struct Player {
	Ant::Vec2f pos;
	Ant::Vec2f size;

	Ant::Texture* sprite;
};

struct Bullet {
	Ant::Vec2f velocity;
	Ant::Vec2f pos;
	Ant::Vec2f size;
	Ant::Texture* sprite;

	bool active;
};

class BulletPool {
	private:
		std::vector<std::unique_ptr<Bullet>> bulletPool;
	public:
		BulletPool() {
			bulletPool.reserve(MAX_BULLETS);

			for (size_t i = 0; i < MAX_BULLETS; i++) {
				bulletPool.push_back(std::make_unique<Bullet>());
			}
		}

		void resetBullet(Bullet& bullet) {
			bullet.active = false;
			bullet.pos = Ant::Vec2f(0.0f, 0.0f);
			bullet.velocity = Ant::Vec2f(0.0f, 0.0f);
		}

		Bullet* acquire() {
			for (auto& bullet : bulletPool) {
				if (!bullet->active) {
					resetBullet(*bullet);
					return bullet.get();
				}
			}

			return nullptr;
		}

		void release(Bullet* bullet) {
			resetBullet(*bullet);
		}

		void forEachActive(std::function<void(Bullet&)> callback) {
			for (auto& bullet : bulletPool) {
				if (bullet->active) {
					callback(*bullet);
				}
			}
		}
};

class BulletManager {
	private:
		BulletPool* pool;
		Ant::Texture* bulletTexture;

	public:
		BulletManager(Ant::Texture* texture, BulletPool* _pool) {
			bulletTexture = texture;
			pool = _pool;
		}

		void setTexture(Ant::Texture* tex) { bulletTexture = tex; }

		void shoot(const Ant::Vec2f& pos, const Ant::Vec2f& size, const Ant::Vec2f& velocity) {
			Bullet* bul = pool->acquire();
			if (bul) {
				bul->pos = pos;
				bul->size = size;
				bul->velocity = velocity;
				bul->sprite = bulletTexture;
				bul->active = true;
			}
		}

		void updateAll(float dt) {
			pool->forEachActive([this, dt](Bullet& bullet){
				bullet.pos += bullet.velocity * dt * 25;

				if (bullet.pos.y <= 0 || bullet.pos.y >= 480) {
					pool->resetBullet(bullet);
				}
			});
		}

		void updateAllCustom(std::function<void(Bullet&)> callback) {
			pool->forEachActive(callback);
		}
};

struct GameContext {
	Player ply;

	//Bullets

	BulletPool pool;
	BulletManager bullets;

	GameContext() : bullets(nullptr, &pool) {}
};

class GameScreen : public Ant::IScreen {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;

		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::ResourceManager<Ant::Text>* text;

		Ant::EventBus* events;
		Ant::ScreenManager* screens;
		Ant::InputService* input;

		GameContext& context;

	public:
		GameScreen(GameContext& _context) : context{_context} {}
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;
			input = services.input;
			text = services.text;

			//Load textures

			textures->load("bulba", (SDL_Renderer*)window->getNativeHandle(), "bulba.jpg");
			textures->load("bullet", (SDL_Renderer*)window->getNativeHandle(), "bullet.jpg");

			text->load("testText", (SDL_Renderer*)window->getNativeHandle(), "test", SDL_Color(255,255,255,255), "arialmt.ttf");

			context.ply.sprite = textures->get("bulba");
			context.ply.pos = Ant::Vec2f(320.0f, 240.0f);
			context.ply.size = Ant::Vec2f(55.0f, 55.0f);

			context.bullets.setTexture(textures->get("bullet"));

			//Input monitor

			input->RegisterKey(ANT_W);
			input->RegisterKey(ANT_A);
			input->RegisterKey(ANT_S);
			input->RegisterKey(ANT_D);
			input->RegisterKey(ANT_SPACE);
		}

		void onUpdate(float dt) override {
			Ant::Text* testText = text->get("testText");

			context.ply.pos += Ant::Vec2f((input->isKeyDown(ANT_D) + (-input->isKeyDown(ANT_A))) * dt * 350, 0);
			context.ply.pos += Ant::Vec2f(0, (input->isKeyDown(ANT_S) + (-input->isKeyDown(ANT_W))) * dt * 350);
			
			if (input->isMousePressed(ANT_BUTTON_LEFT)) {
				context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(0.0f, -27.0f));
				context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(8.0f, -27.0f));
				context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(-8.0f, -27.0f));
			}

			testText->updateText("MouseXY: " + std::to_string(input->getMouseX()) + " " + std::to_string(input->getMouseY()) + " Left pressed: " + std::to_string(input->isMouseDown(ANT_BUTTON_LEFT)));

			context.bullets.updateAll(dt);
		}

		void onRender() override {
			renderer->QueueTexture(context.ply.sprite, context.ply.pos, context.ply.size, 1);

			context.bullets.updateAllCustom([&](Bullet& bullet) {
				renderer->QueueTexture(bullet.sprite, bullet.pos, bullet.size, 0);
			});

			Ant::Text* testText = text->get("testText");

			renderer->QueueText(testText,Ant::Vec2f(320.0f,25.0f), Ant::Vec2f(testText->getWidth()/1.2, testText->getHeight()/1.2), 2);
		}

		void onClose() override {

		}
};

class AntouhaProject : public Ant::IGameLogic {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::EventBus* events;
		Ant::ScreenManager* screens;
		Ant::InputService* input;
		Ant::ResourceManager<Ant::Text>* text;

		GameContext context;

	public:
		void init(const Ant::GameServices& services) override {
			window = services.window;
			renderer = services.renderer;
			textures = services.textures;
			events = services.eventBus;
			screens = services.screens;
			input = services.input;
			text = services.text;

			Ant::IScreen* mainScr = new GameScreen(context);
			mainScr->init(services);
			screens->pushScreen(mainScr);
		}

		void onUpdate(float dt) override {

		}

		void onQuit() override {

		}
};
