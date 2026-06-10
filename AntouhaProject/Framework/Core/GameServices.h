#pragma once

#include "../Renderer/IRenderer.h"
#include "../Window/IWindow.h"
#include "../ResourceManager/ResourceManager.h"
#include  "../ResourceManager/Resources/Texture.h"
#include "../Event/EventBus.h"
#include "../ScreenManager/ScreenManager.h"

namespace Ant {
	struct GameServices {
		//Main

		IWindow* window;
		IRenderer* renderer;
		EventBus* eventBus;
		
		//Managers

		ResourceManager<Texture>* textures;
		ScreenManager* screens;
	};
}