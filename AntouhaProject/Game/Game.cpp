#include "Game.h"
#include "Levels/Level1.h"
#include "Levels/MainMenu.h"

void AntouhaProject::init(const Ant::GameServices& services) {
	window = services.window;
	renderer = services.renderer;
	textures = services.textures;
	events = services.eventBus;
	screens = services.screens;
	input = services.input;
	text = services.text;
	animations = services.animations;

	auto mainScr = std::make_unique<MainMenu>(context);
	mainScr->init(services);
	screens->pushScreen(std::move(mainScr));
}

void AntouhaProject::onUpdate(float dt) {

}

void AntouhaProject::onQuit() {

}