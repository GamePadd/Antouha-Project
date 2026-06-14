#pragma once

#include "../GameStructures.h"
#include "../../Framework/FrameworkH.h"
#include "BulletPool.h"

class BulletManager {
private:
	BulletPool* pool;
	Ant::Texture* bulletTexture;

public:
	BulletManager(Ant::Texture* texture, BulletPool* _pool) {
		bulletTexture = texture;
		pool = _pool;
	}

	void setTexture(Ant::Texture* tex) { bulletTexture = tex; }
	void shoot(const Ant::Vec2f& pos, const Ant::Vec2f& size, const Ant::Vec2f& velocity);
	void updateAll(float dt);
	void updateAllCustom(std::function<void(Bullet&)> callback);
};