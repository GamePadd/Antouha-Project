#pragma once

#include "../../Framework/FrameworkH.h"
#include "../Context.h"

class Level1 : public Ant::IScreen {
private:
	Ant::IWindow* window;
	Ant::IRenderer* renderer;

	Ant::ResourceManager<Ant::Texture>* textures;
	Ant::ResourceManager<Ant::Text>* text;

	Ant::EventBus* events;
	Ant::ScreenManager* screens;
	Ant::InputService* input;

	GameContext& context;

public:
	Level1(GameContext& _context) : context{ _context } {}
	void init(const Ant::GameServices& services) override;
	void onUpdate(float dt) override;
	void onRender() override;
	void onClose() override;
};