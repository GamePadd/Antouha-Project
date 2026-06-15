#include "Level1.h"

/*

0-9 BG Layers
10-19 - Game Layers
20-31 - UI Layers

*/

void Level1::DrawUI() {
	renderer->QueueTexture(UITextures.Background, Ant::Vec2f(320.0f, 240.0f), Ant::Vec2f(640.0f, 480.0f), 0);
	renderer->QueueTexture(UITextures.Frame, Ant::Vec2f(320.0f, 240.0f), Ant::Vec2f(640.0f, 480.0f), 20);
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
	textures->load("mainframe", (SDL_Renderer*)window->getNativeHandle(), "Resources/UI/MainFrame.png");
	textures->load("bg1", (SDL_Renderer*)window->getNativeHandle(), "Resources/Backgrounds/Background1.png");

	UITextures.Background = textures->get("bg1");
	UITextures.Frame = textures->get("mainframe");

	context.ply.sprite = textures->get("player");
	context.ply.pos = Ant::Vec2f(320.0f, 240.0f);
	context.ply.size = Ant::Vec2f(32.f, 32.f);

	context.bullets.setTexture(textures->get("bullet1"));

	//Input monitor

	input->RegisterKey(ANT_W);
	input->RegisterKey(ANT_A);
	input->RegisterKey(ANT_S);
	input->RegisterKey(ANT_D);
	input->RegisterKey(ANT_SPACE);
}

//TODO: Вынеси блять потом все по нормальным методам для players и тд нахуй, а то че за хуйня то блять дебил костыльный

void Level1::onUpdate(float dt) {
	// x 32 - 416 y 32 - 448

	//Controls

	context.ply.pos += Ant::Vec2f((input->isKeyDown(ANT_D) + (-input->isKeyDown(ANT_A))) * dt * 350, 0);
	context.ply.pos += Ant::Vec2f(0, (input->isKeyDown(ANT_S) + (-input->isKeyDown(ANT_W))) * dt * 350);

	if (context.ply.pos.x > 416) { context.ply.pos.x = 416; }
	if (context.ply.pos.x < 32) { context.ply.pos.x = 32; }
	if (context.ply.pos.y > 448) { context.ply.pos.y = 448; }
	if (context.ply.pos.y < 32) { context.ply.pos.y = 32; }

	if (input->isMousePressed(ANT_BUTTON_LEFT)) {
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(0.0f, -27.0f));
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(8.0f, -27.0f));
		context.bullets.shoot(context.ply.pos, Ant::Vec2f(10.0f, 10.0f), Ant::Vec2f(-8.0f, -27.0f));
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

void Level1::onClose() {

}