#include "Animation.h"

namespace Ant {
	void ValueFAnimation::update(Uint64 currentTime) {
		Uint64 t = (currentTime - startTime) / duration;
		*value = static_cast<float>(std::lerp(startValue, endValue, t));
	}

	ValueFAnimation::ValueFAnimation(Uint64 _startTime, Uint64 _duration, float* _value, float goal) {
		startTime = _startTime;
		endTime = startTime + _duration;
		duration = _duration;
		value = _value;
		startValue = *_value;
		endValue = goal;
	}

	void VectorFAnimation::update(Uint64 currentTime) {
		Uint64 t = (currentTime - startTime) / duration;
		*value = Vec2f(
			static_cast<float>(std::lerp(startValue.x, endValue.x, t)), 
			static_cast<float>(std::lerp(startValue.y, endValue.y, t))
		);
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