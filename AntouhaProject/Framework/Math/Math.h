#pragma once

namespace Ant {
	struct Vec2f {
		float x;
		float y;

		Vec2f operator+(const Vec2f& other) const {
			return Vec2f(this->x + other.x, this->y + other.y);
		}
	};

	struct Vec2i {
		int x;
		int y;

		Vec2i operator+(const Vec2i& other) const {
			return Vec2i(this->x + other.x, this->y + other.y);
		}
	};
}