#include "AnimationManager.h"

namespace Ant {

	//Anim one float value
	void AnimationManager::start(std::string name, float* _value, float _goal, Uint64 duration) {
		Uint64 st = SDL_GetTicks();
		animations[name] = ValueFAnimation(st, duration, _value, _goal);
	}

	//Anim float vector
	void AnimationManager::start(std::string name, Vec2f* _value, Vec2f _goal, Uint64 duration) {
		Uint64 st = SDL_GetTicks();
		animations[name] = VectorFAnimation(st, duration, _value, _goal);
	}

	void AnimationManager::stop(std::string animationName) {
		animations.erase(animationName);
	}

	void AnimationManager::updateAll(float dt, Uint64 currentTime) {
		for (auto& [name,anim] : animations) {
			anim.update(currentTime);
		}
	}
}