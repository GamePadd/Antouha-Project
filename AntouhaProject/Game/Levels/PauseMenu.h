#pragma once

#include "../../Framework/FrameworkH.h"
#include "../Context.h"
#include "../UI/Button.h"

class PauseMenu : public Ant::IScreen {
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

	Button* continueButton;
	Button* exitButton;

public:
	PauseMenu(GameContext& _context) : context{ _context } {}
	~PauseMenu();

	void init(const Ant::GameServices& services) override;
	void onUpdate(float dt) override;
	void onRender() override;
	void onClose() override;
};