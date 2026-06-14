#pragma once

#include "../../Framework/FrameworkH.h"
#include "../Context.h"
#include "../UI/Button.h"

class MainMenu : public Ant::IScreen {
private:
	Ant::IWindow* window;
	Ant::IRenderer* renderer;

	Ant::ResourceManager<Ant::Texture>* textures;
	Ant::ResourceManager<Ant::Text>* text;

	Ant::EventBus* events;
	Ant::ScreenManager* screens;
	Ant::InputService* input;

	GameContext& context;

	//Buttons

	Button* playButton;
	Button* exitButton;

public:
	MainMenu(GameContext& _context) : context{ _context } {}
	~MainMenu();

	void init(const Ant::GameServices& services) override;
	void onUpdate(float dt) override;
	void onRender() override;
	void onClose() override;
};