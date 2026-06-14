#include "Level1.h"

void Level1::init(const Ant::GameServices& services) {
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

	text->load("testText", (SDL_Renderer*)window->getNativeHandle(), "test", SDL_Color(255, 255, 255, 255), "arialmt.ttf");

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

void Level1::onUpdate(float dt) {
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

void Level1::onRender() {
	renderer->QueueTexture(context.ply.sprite, context.ply.pos, context.ply.size, 1);

	context.bullets.updateAllCustom([&](Bullet& bullet) {
		renderer->QueueTexture(bullet.sprite, bullet.pos, bullet.size, 0);
		});

	Ant::Text* testText = text->get("testText");

	renderer->QueueText(testText, Ant::Vec2f(320.0f, 25.0f), Ant::Vec2f(testText->getWidth() / 1.2, testText->getHeight() / 1.2), 2);
}

void Level1::onClose() {

}