#pragma once
#include "Animation.h"
#include <SDL3/SDL_timer.h>
#include <unordered_map>
#include <string>
#include <functional>

namespace Ant {
	class AnimationManager {
	private:
		std::unordered_map<std::string, IAnimation> animations;
	public:
		void start(std::string name, float* _value, float _goal, Uint64 duration);
		void start(std::string name, Vec2f* _value, Vec2f _goal, Uint64 duration);

		void stop(std::string animationName);

		void updateAll(float dt, Uint64 currentTime);
	};
}