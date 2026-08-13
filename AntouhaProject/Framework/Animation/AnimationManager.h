#pragma once
#include "Animation.h"
#include <SDL3/SDL_timer.h>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

namespace Ant {
	class AnimationManager {
	private:
		std::unordered_map<std::string, std::unique_ptr<IAnimation>> animations;
	public:
		bool isPlaying(const std::string& name);
		void start(const std::string& name, float* _value, float _goal, float duration);
		void start(const std::string& name, Vec2f* _value, Vec2f _goal, float duration);

		void stop(const std::string& animationName);

		void updateAll(float dt, Uint64 currentTime);
	};
}