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

	Ant::IScreen* mainScr = new MainMenu(context);
	mainScr->init(services);
	screens->pushScreen(mainScr);
}

void AntouhaProject::onUpdate(float dt) {

}

void AntouhaProject::onQuit() {

}