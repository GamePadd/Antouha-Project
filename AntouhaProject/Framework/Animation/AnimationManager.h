#pragma once
#include <SDL3/SDL_timer.h>
#include <unordered_map>
#include <string>
#include <functional>

namespace Ant {
	struct Animation {
		Uint64 startTime;
		Uint64 endTime;

		float* value;
		float goal;

		std::function<void(void)> onEnd;
	};

	class AnimationManager {
	private:
		std::unordered_map<std::string, Animation> AnimationPool;
	public:
		void start(float* _value, float _goal, float duration);
		void stop(std::string animationName);

		void updateAll(float dt, Uint64 currentTime);
	};
}