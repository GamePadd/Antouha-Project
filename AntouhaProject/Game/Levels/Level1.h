#pragma once

#include "../../Framework/FrameworkH.h"
#include "../Context.h"


struct LevelResources {
	Ant::Texture* Background;
	Ant::Texture* Frame;

	std::unordered_map<std::string, Ant::Texture*> bulletsTextures;
};

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

	//Level

	LevelResources levelResources;

public:
	//IGameLogic
	Level1(GameContext& _context) : context{ _context } {}
	void init(const Ant::GameServices& services) override;
	void onUpdate(float dt) override;
	void onRender() override;
	void onClose() override;

	//UI

	void DrawUI();
};