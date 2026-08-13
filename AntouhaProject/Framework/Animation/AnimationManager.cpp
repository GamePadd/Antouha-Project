#include "AnimationManager.h"
#include <iostream>
namespace Ant {

	//Anim one float value
	bool AnimationManager::isPlaying(const std::string& name) {
		if (animations.find(name) != animations.end()) { return true; }
		return false;
	}
	void AnimationManager::start(const std::string& name, float* _value, float _goal, float duration) {
		if (animations.find(name) != animations.end()) { return; }
		Uint64 st = SDL_GetTicks();
		animations[name] = std::make_unique<ValueFAnimation>(st, (Uint64)duration, _value, _goal);
		//std::cout << "animation started\n";
	}

	//Anim float vector
	void AnimationManager::start(const std::string& name, Vec2f* _value, Vec2f _goal, float duration) {
		if (animations.find(name) != animations.end()) { return; }

		Uint64 st = SDL_GetTicks();
		animations[name] = std::make_unique<VectorFAnimation>(st, (Uint64)duration, _value, _goal);
	}

	void AnimationManager::stop(const std::string& animationName) {
		animations.erase(animationName);
		std::cout << "animation stopped\n";
	}

	void AnimationManager::updateAll(float dt, Uint64 currentTime) {
		for (auto it = animations.begin(); it != animations.end();) {
			if (it->second->update(currentTime)) {
				it = animations.erase(it);
			}
			else {
				++it;
			}
		}
	}
}