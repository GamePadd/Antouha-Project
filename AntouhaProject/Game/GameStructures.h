#pragma once

#include "../Framework/FrameworkH.h"

struct Player {
	Ant::Vec2f pos;
	Ant::Vec2f size;

	Ant::Texture* sprite;
	
	//Mechanix
	
	Uint64 shootCooldown = 5;
	int speed = 350;

	//Other
	
	Uint64 lastShootTime;
	
	//TODO: потом сделай чтобы он возвращал byte как маску, где каждый бит означает что-то из сделаного игроком, например выстрел на первом бите и тд

	bool Update(Ant::InputService* input, float dt) {
		Uint64 currentTime = SDL_GetTicks();

		if (input->isKeyPressed(ANT_LSHIFT)) { speed = 225; }
		if (input->isKeyReleased(ANT_LSHIFT)) { speed = 350; }

		pos += Ant::Vec2f((input->isKeyDown(ANT_RIGHT) + (-input->isKeyDown(ANT_LEFT))) * dt * speed, 0);
		pos += Ant::Vec2f(0, (input->isKeyDown(ANT_DOWN) + (-input->isKeyDown(ANT_UP))) * dt * speed);

		if (pos.x > 416) {pos.x = 416; }
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

	bool active;
};