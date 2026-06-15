#include "BulletPool.h"

Bullet* BulletPool::acquire() {
	for (auto& bullet : bulletPool) {
		if (!bullet->active) {
			bullet->Reset();
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