#include "Animation.h"
#include <algorithm>
namespace Ant {
	bool ValueFAnimation::update(Uint64 currentTime) {
		Uint64 t = (currentTime - startTime) / duration;
		t = std::clamp(static_cast<float>(t), 0.0f, 1.0f);

		*value = static_cast<float>(std::lerp(startValue, endValue, t));

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
		Uint64 t = (currentTime - startTime) / duration;
		t = std::clamp(static_cast<float>(t), 0.0f, 1.0f);

		*value = Vec2f(
			static_cast<float>(std::lerp(startValue.x, endValue.x, t)), 
			static_cast<float>(std::lerp(startValue.y, endValue.y, t))
		);

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