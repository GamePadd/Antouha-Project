#pragma once

#include "../Framework/FrameworkH.h"

class TestGame : public Ant::IGameLogic {
	private:
		Ant::IWindow* window;
		Ant::IRenderer* renderer;
		Ant::ResourceManager<Ant::Texture>* textureManager;
		Ant::EventBus* events;

	public:
		void init(const Ant::GameServices& services) override;
		void onUpdate(float dt) override;
		void onQuit() override;
};
