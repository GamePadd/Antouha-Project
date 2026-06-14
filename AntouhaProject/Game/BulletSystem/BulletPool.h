#pragma once

#include "../GameStructures.h"
#include "../../Framework/FrameworkH.h"

#define MAX_BULLETS 2048

class BulletPool {
private:
	std::vector<std::unique_ptr<Bullet>> bulletPool;
public:
	BulletPool() {
		bulletPool.reserve(MAX_BULLETS);

		for (size_t i = 0; i < MAX_BULLETS; i++) {
			bulletPool.push_back(std::make_unique<Bullet>());
		}
	}

	void resetBullet(Bullet& bullet);
	Bullet* acquire();
	void release(Bullet* bullet) { resetBullet(*bullet); }
	void forEachActive(std::function<void(Bullet&)> callback);
};