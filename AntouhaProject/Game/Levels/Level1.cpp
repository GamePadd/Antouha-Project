#include "Level1.h"
#include "MainMenu.h"
#include "PauseMenu.h"

/*

0-9 BG Layers
10-19 - Game Layers
20-31 - UI Layers

*/

void Level1::DrawUI() {
	renderer->QueueTexture(levelResources.Background, Ant::Vec2f(320.0f, 240.0f), Ant::Vec2f(640.0f, 480.0f), 0);
	renderer->QueueTexture(levelResources.Frame, Ant::Vec2f(320.0f, 240.0f), Ant::Vec2f(640.0f, 480.0f), 20);
}

void Level1::init(const Ant::GameServices& services) {
	//Service init

	window = services.window;
	renderer = services.renderer;
	textures = services.textures;
	events = services.eventBus;
	screens = services.screens;
	input = services.input;
	text = services.text;

	//Load textures

	textures->load("player", (SDL_Renderer*)window->getNativeHandle(), "Resources/Players/player1.png");

	textures->load("bullet1", (SDL_Renderer*)window->getNativeHandle(), "Resources/Bullets/bullet1.png");
	textures->load("bullet2", (SDL_Renderer*)window->getNativeHandle(), "Resources/Bullets/bullet2.png");
	textures->load("bullet3", (SDL_Renderer*)window->getNativeHandle(), "Resources/Bullets/bullet3.png");

	textures->load("mainframe", (SDL_Renderer*)window->getNativeHandle(), "Resources/UI/MainFrame.png");
	textures->load("bg1", (SDL_Renderer*)window->getNativeHandle(), "Resources/Backgrounds/Background1.png");

	//Save resource textures;

	levelResources.Background = textures->get("bg1");
	levelResources.Frame = textures->get("mainframe");

	levelResources.bulletsTextures["bullet1"] = textures->get("bullet1");
	levelResources.bulletsTextures["bullet2"] = textures->get("bullet2");
	levelResources.bulletsTextures["bullet3"] = textures->get("bullet3");

	context.ply.sprite = textures->get("player");

	//Input monitor

	input->RegisterKey(ANT_W);
	input->RegisterKey(ANT_A);
	input->RegisterKey(ANT_S);
	input->RegisterKey(ANT_D);

	input->RegisterKey(ANT_UP);
	input->RegisterKey(ANT_LEFT);
	input->RegisterKey(ANT_DOWN);
	input->RegisterKey(ANT_RIGHT);

	input->RegisterKey(ANT_SPACE);
	input->RegisterKey(ANT_LSHIFT);
	input->RegisterKey(ANT_Z);
	input->RegisterKey(ANT_ESCAPE);
}

void Level1::onUpdate(float dt) {
	// x 32 - 416 y 32 - 448

	//Controls

	if (input->isKeyPressed(ANT_ESCAPE)) {
		Ant::GameServices services;
		services.window = window;
		services.renderer = renderer;
		services.eventBus = events;
		services.textures = textures;
		services.screens = screens;
		services.input = input;
		services.text = text;

		auto scr = std::make_unique<PauseMenu>(context);
		scr->init(services);
		screens->pushScreen(std::move(scr));
	}

	if (context.ply.Update(input, dt)) {
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(25.0f, 25.0f), Ant::Vec2f(0.0f, -27.0f), levelResources.bulletsTextures["bullet2"]);
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(15.0f, 15.0f), Ant::Vec2f(8.0f, -27.0f), levelResources.bulletsTextures["bullet1"]);
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(15.0f, 15.0f), Ant::Vec2f(-8.0f, -27.0f), levelResources.bulletsTextures["bullet1"]);
	}

	context.bullets.updateAll(dt);
}

void Level1::onRender() {
	renderer->QueueTexture(context.ply.sprite, context.ply.pos, context.ply.size, 11);

	context.bullets.updateAllCustom([&](Bullet& bullet) {
		renderer->QueueTexture(bullet.sprite, bullet.pos, bullet.size, 10);
	});

	DrawUI();
}

void Level1::onClose() {}