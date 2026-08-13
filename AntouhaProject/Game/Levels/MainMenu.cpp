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
	animations = services.animations;

	text->load("GameName", (SDL_Renderer*)window->getNativeHandle(), "Antouha Project", SDL_Color(255, 255, 255, 255), "Resources/UI/Fonts/pixel.ttf");

	playButton = new Button(services, "playButtonText", "Play");
	exitButton = new Button(services, "exitButtonText", "Exit");

	playButton->setPos(Ant::Vec2f(320.0f, 240.0f));
	exitButton->setPos(Ant::Vec2f(320.0f, 320.0f));

	playButton->setOnHover([this]() {
		playButton->setText("Play", SDL_Color(0, 255, 0, 255), 64);
		if (!playButton->isHovered) {
			animations->start("PlayHoverUp", playButton->getPos(), Ant::Vec2f(320.0f, 240.0f) - Ant::Vec2f(0.0f, 25.0f), 500.0f);
		}
	});

	playButton->setOnLeave([this]() {
		playButton->setText("Play", SDL_Color(255, 255, 255, 255),64);
		if (playButton->isHovered) {
			animations->start("PlayHoverDown", playButton->getPos(), Ant::Vec2f(320.0f, 240.0f), 500.0f);
		}
	});

	playButton->setOnClick([this, services](){
		auto level1Scr = std::make_unique<Level1>(context);
		level1Scr->init(services);
		screens->pushScreen(std::move(level1Scr));
	});

	exitButton->setOnHover([this]() {
		exitButton->setText("Exit", SDL_Color(255, 0, 0, 255), 64);
		if (!exitButton->isHovered) {
			animations->start("ExitHoverUp", exitButton->getPos(), Ant::Vec2f(320.0f, 320.0f) - Ant::Vec2f(0.0f, 25.0f), 500.0f);
		}
	});

	exitButton->setOnLeave([this]() {
		exitButton->setText("Exit", SDL_Color(255, 255, 255, 255), 64);
		if (exitButton->isHovered) {
			animations->start("ExitHoverDown", exitButton->getPos(), Ant::Vec2f(320.0f, 320.0f), 500.0f);
		}
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

void MainMenu::onClose() {}

MainMenu::~MainMenu() {
	delete playButton;
	delete exitButton;
}