#pragma once

#include "../GameStructures.h"
#include "../../Framework/FrameworkH.h"
#include "BulletPool.h"

class BulletManager {
private:
	BulletPool* pool;

public:
	BulletManager(BulletPool* _pool) {
		pool = _pool;
	}

	void shoot(const Ant::Vec2f& pos, const Ant::Vec2f& size, const Ant::Vec2f& velocity, Ant::Texture* bulletTexture);
	void updateAll(float dt);
	void updateAllCustom(std::function<void(Bullet&)> callback);
};