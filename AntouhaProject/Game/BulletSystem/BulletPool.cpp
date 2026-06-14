#include "BulletPool.h"

void BulletPool::resetBullet(Bullet& bullet) {
	bullet.active = false;
	bullet.pos = Ant::Vec2f(0.0f, 0.0f);
	bullet.velocity = Ant::Vec2f(0.0f, 0.0f);
}

Bullet* BulletPool::acquire() {
	for (auto& bullet : bulletPool) {
		if (!bullet->active) {
			resetBullet(*bullet);
			return bullet.get();
		}
	}

	return nullptr;
}

void BulletPool::forEachActive(std::function<void(Bullet&)> callback) {
	for (auto& bullet : bulletPool) {
		if (bullet->active) {
			callback(*bullet);
		}
	}
}