#include "BulletManager.h"

void BulletManager::shoot(const Ant::Vec2f& pos, const Ant::Vec2f& size, const Ant::Vec2f& velocity) {
	Bullet* bul = pool->acquire();
	if (bul) {
		bul->pos = pos;
		bul->size = size;
		bul->velocity = velocity;
		bul->sprite = bulletTexture;
		bul->active = true;
	}
}

void BulletManager::updateAll(float dt) {
	pool->forEachActive([this, dt](Bullet& bullet) {
		bullet.pos += bullet.velocity * dt * 25;

		if (bullet.pos.y <= 0 || bullet.pos.y >= 480) {
			pool->resetBullet(bullet);
		}
	});
}

void BulletManager::updateAllCustom(std::function<void(Bullet&)> callback) {
	pool->forEachActive(callback);
}