#pragma once

#include "../Renderer/IRenderer.h"
#include "../Window/IWindow.h"
#include "../ResourceManager/ResourceManager.h"
#include  "../ResourceManager/Resources/Texture.h"
#include  "../ResourceManager/Resources/Text.h"
#include "../Event/EventBus.h"
#include "../ScreenManager/ScreenManager.h"
#include "../InputService/InputService.h"

namespace Ant {
	struct GameServices {
		//Main

		IWindow* window;
		IRenderer* renderer;
		EventBus* eventBus;
		
		//Managers

		ResourceManager<Texture>* textures;
		ResourceManager<Text>* text;

		ScreenManager* screens;

		//Services

		InputService* input;
	};
}