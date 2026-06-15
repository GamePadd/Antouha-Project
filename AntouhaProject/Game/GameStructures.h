#pragma once

#include "../Framework/FrameworkH.h"
#include <cmath>

struct LevelResources {
	Ant::Texture* Background;
	Ant::Texture* Frame;

	std::unordered_map<std::string, Ant::Texture*> bulletsTextures;
};

struct Player {
	Ant::Vec2f pos = Ant::Vec2f(320.0f, 240.0f);
	Ant::Vec2f size = Ant::Vec2f(32.0f, 32.0f);

	Ant::Texture* sprite;
	
	//Mechanix
	
	Uint64 shootCooldown = 50;
	int speed = 350;

	//Other
	
	Uint64 lastShootTime;
	
	//TODO: потом сделай чтобы он возвращал byte как маску, где каждый бит означает что-то из сделаного игроком, например выстрел на первом бите и тд

	bool Update(Ant::InputService* input, float dt) {
		Uint64 currentTime = SDL_GetTicks();

		if (input->isKeyPressed(ANT_LSHIFT)) { speed = 225; }
		if (input->isKeyReleased(ANT_LSHIFT)) { speed = 350; }

		bool up = input->isKeyDown(ANT_UP);
		bool down = input->isKeyDown(ANT_DOWN);
		bool left = input->isKeyDown(ANT_LEFT);
		bool right = input->isKeyDown(ANT_RIGHT);

		float dx = right - left;
		float dy = down - up;

		if (dx != 0.0f && dy != 0.0f) {
			float len = sqrt(dx * dx + dy * dy);
			dx /= len;
			dy /= len;
		}

		pos += Ant::Vec2f(dx*speed*dt,dy*speed*dt);

		if (pos.x > 416) { pos.x = 416; }
		if (pos.x < 32) { pos.x = 32; }
		if (pos.y > 448) { pos.y = 448; }
		if (pos.y < 32) { pos.y = 32; }

		if (input->isKeyDown(ANT_Z)) {
			if (currentTime >= lastShootTime + shootCooldown) {
				lastShootTime = currentTime;
				return true;
			}
		}

		return false;
	}
};

struct Bullet {
	Ant::Vec2f velocity;
	Ant::Vec2f pos;
	Ant::Vec2f size;

	Ant::Texture* sprite;

	void Update(float dt) {
		pos += velocity * dt * 25;
	}

	void Reset() {
		active = false;
		pos = Ant::Vec2f(0.0f, 0.0f);
		velocity = Ant::Vec2f(0.0f, 0.0f);
	}

	bool active;
};