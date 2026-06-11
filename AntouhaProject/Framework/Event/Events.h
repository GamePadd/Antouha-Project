#pragma once
#include "IEvent.h"
#include <SDL3/SDL.h>

namespace Ant {

	struct QuitEvent : public IEvent{};
	struct PollEvent : public IEvent { 
		SDL_Event& e; 
		PollEvent(SDL_Event& _e) : e(_e) {}
	};
}