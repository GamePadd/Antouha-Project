#include "Animation.h"
#include <algorithm>
#include <SDL3/SDL.h>
namespace Ant {
	bool ValueFAnimation::update(Uint64 currentTime) {
		float t = ((long double)currentTime - (long double)startTime) / (long double)duration;
		t = std::clamp(static_cast<float>(t), 0.0f, 1.0f);
		*value = static_cast<float>(std::lerp(startValue, endValue, t));
		//lOG
		//SDL_Log("startTime = %d,currentTime = %d, endTime = %d, duration = %d, startValue = %f, endVal = %f, t = %f, value = %f",
		//	startTime, currentTime, endTime, duration, startValue, endValue, t, *value);

		return t >= 1.0f;
	}

	ValueFAnimation::ValueFAnimation(Uint64 _startTime, Uint64 _duration, float* _value, float goal) {
		startTime = _startTime;
		endTime = startTime + _duration;
		duration = _duration;
		value = _value;
		startValue = *_value;
		endValue = goal;
	}

	bool VectorFAnimation::update(Uint64 currentTime) {
		float t = ((long double)currentTime - (long double)startTime) / (long double)duration;
		t = std::clamp(static_cast<float>(t), 0.0f, 1.0f);

		*value = Vec2f(
			static_cast<float>(std::lerp(startValue.x, endValue.x, t)), 
			static_cast<float>(std::lerp(startValue.y, endValue.y, t))
		);

		//SDL_Log("startTime = %d,currentTime = %d, endTime = %d, duration = %d, startValue = %f, endVal = %f, t = %f, valuex = %f, valuey = %f",
		//	startTime, currentTime, endTime, duration, startValue, endValue, t, (*value).x,(*value).y);

		return t >= 1.0f;
	}

	VectorFAnimation::VectorFAnimation(Uint64 _startTime, Uint64 _duration, Ant::Vec2f* _value, Ant::Vec2f goal) {
		startTime = _startTime;
		endTime = startTime + _duration;
		duration = _duration;
		value = _value;
		startValue = *_value;
		endValue = goal;
	}
}