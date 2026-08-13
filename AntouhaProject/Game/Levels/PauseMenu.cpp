#include "PauseMenu.h"
#include "MainMenu.h"
#include "Level1.h"

void PauseMenu::init(const Ant::GameServices& services) {
	window = services.window;
	renderer = services.renderer;
	textures = services.textures;
	events = services.eventBus;
	screens = services.screens;
	input = services.input;
	text = services.text;
	animations = services.animations;

	text->load("PauseText", (SDL_Renderer*)window->getNativeHandle(), "Pause", SDL_Color(255, 255, 255, 255), "Resources/UI/Fonts/pixel.ttf");

	continueButton = new Button(services, "continueButtonText", "Continue");
	exitButton = new Button(services, "exitButtonText", "Exit");

	continueButton->setPos(Ant::Vec2f(320.0f, 240.0f));
	exitButton->setPos(Ant::Vec2f(320.0f, 320.0f));

	continueButton->setOnHover([this]() {
		continueButton->setText("Continue", SDL_Color(0, 255, 0, 255), 64);
	});

	continueButton->setOnLeave([this]() {
		continueButton->setText("Continue", SDL_Color(255, 255, 255, 255), 64);
	});

	continueButton->setOnClick([this, services]() {
		screens->popScreen();
	});

	exitButton->setOnHover([this]() {
		exitButton->setText("Exit", SDL_Color(255, 0, 0, 255),64);
	});

	exitButton->setOnLeave([this]() {
		exitButton->setText("Exit", SDL_Color(255, 255, 255, 255),64);
	});

	exitButton->setOnClick([&]() {
		screens->popScreen();
		screens->popScreen();
	});
}

void PauseMenu::onUpdate(float dt) {
	continueButton->updateState();
	exitButton->updateState();
	if (input->isKeyPressed(ANT_ESCAPE)) {screens->popScreen();}
}

void PauseMenu::onRender() {
	Ant::Text* GameName = text->get("PauseText");
	renderer->QueueText(GameName, Ant::Vec2f(320.0f, 64), Ant::Vec2f(GameName->getWidth(), GameName->getHeight()), 1);

	continueButton->render(1);
	exitButton->render(1);
}

void PauseMenu::onClose() {}

PauseMenu::~PauseMenu() {
	delete continueButton;
	delete exitButton;
}