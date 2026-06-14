#include "MainMenu.h"
#include "Level1.h"

void MainMenu::init(const Ant::GameServices& services) {
	window = services.window;
	renderer = services.renderer;
	textures = services.textures;
	events = services.eventBus;
	screens = services.screens;
	input = services.input;
	text = services.text;

	textures->load("bulba", (SDL_Renderer*)window->getNativeHandle(), "bulba.jpg");
	text->load("GameName", (SDL_Renderer*)window->getNativeHandle(), "Antouha Project", SDL_Color(255, 255, 255, 255), "arialmt.ttf");

	playButton = new Button(services, "playButtonText", "Play", SDL_Color(255,255,255,255),"bulba");
	exitButton = new Button(services, "exitButtonText", "Exit", SDL_Color(255, 255, 255, 255), "bulba");

	playButton->setPos(Ant::Vec2f(320.0f, 240.0f));
	exitButton->setPos(Ant::Vec2f(320.0f, 320.0f));

	playButton->setOnHover([this]() {
		playButton->setText("Play", SDL_Color(0, 255, 0, 255));
	});

	playButton->setOnLeave([this]() {
		playButton->setText("Play", SDL_Color(255, 255, 255, 255));
	});

	playButton->setOnClick([this, services](){
		Ant::IScreen* level1Scr = new Level1(context);
		level1Scr->init(services);
		screens->pushScreen(level1Scr);
	});

	exitButton->setOnHover([this]() {
		exitButton->setText("Exit", SDL_Color(255, 0, 0, 255));
	});

	exitButton->setOnLeave([this]() {
		exitButton->setText("Exit", SDL_Color(255, 255, 255, 255));
	});

	exitButton->setOnClick([&]() {
		events->queueEvent<Ant::QuitEvent>(Ant::QuitEvent());
	});
}

void MainMenu::onUpdate(float dt) {
	playButton->updateState();
	exitButton->updateState();
}

void MainMenu::onRender() {
	Ant::Text* GameName = text->get("GameName");
	renderer->QueueText(GameName, Ant::Vec2f(320.0f, 64), Ant::Vec2f(GameName->getWidth(), GameName->getHeight()), 1);

	playButton->render(1);
	exitButton->render(1);
}

void MainMenu::onClose() {

}

MainMenu::~MainMenu() {
	delete playButton;
	delete exitButton;
}