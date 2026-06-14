#pragma once

#include "../Framework/FrameworkH.h"
#include "Context.h"

class AntouhaProject : public Ant::IGameLogic {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textures;
		Ant::EventBus* events;
		Ant::ScreenManager* screens;
		Ant::InputService* input;
		Ant::ResourceManager<Ant::Text>* text;

		GameContext context;

	public:
		void init(const Ant::GameServices& services) override;
		void onUpdate(float dt) override;
		void onQuit() override;
};
