#pragma once

#include "../Engine/EngineH.h"

class TestGame : public Ant::IGameLogic {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textureManager;
		Ant::EventBus* events;

	public:
		void init(const Ant::GameServices&) override;
		void update(float) override;
		void render() override;
		void quit() override;
};
