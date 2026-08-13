#pragma once

#include <SDL3/SDL_timer.h>
#include <unordered_map>
#include <string>
#include <functional>
#include "../Math/Math.h"

namespace Ant {
	class IAnimation {
	public:
		virtual ~IAnimation() = default;
		virtual bool update(Uint64 currentTime) = 0; //return true = animation is done

		//std::function<void(void)> onEnd;
	};

	class ValueFAnimation : public IAnimation {
	private:
		Uint64 startTime;
		Uint64 endTime;

		Uint64 duration;

		float* value;

		float startValue;
		float endValue;
	public:
		bool update(Uint64 currentTime) override;
		ValueFAnimation(Uint64 _startTime, Uint64 _duration, float* _value, float goal);
	};

	class VectorFAnimation : public IAnimation {
	private:
		Uint64 startTime;
		Uint64 endTime;

		Uint64 duration;

		Ant::Vec2f* value;

		Ant::Vec2f startValue;
		Ant::Vec2f endValue;

	public:
		bool update(Uint64 currentTime) override;
		VectorFAnimation(Uint64 _startTime, Uint64 _duration, Ant::Vec2f* _value, Ant::Vec2f goal);
	};
}