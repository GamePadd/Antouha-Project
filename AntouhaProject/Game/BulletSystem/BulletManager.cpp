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
	//TODO: ¬ынеси координаты окна в отдельные константы или переменные и передавай их через конструктор
	
	// x 32 - 416 y 32 - 448

	pool->forEachActive([this, dt](Bullet& bullet) {
		bullet.pos += bullet.velocity * dt * 25;

		if (bullet.pos.y < 32 || bullet.pos.y > 448 ||
			bullet.pos.x < 32 || bullet.pos.x > 416) {
			pool->resetBullet(bullet);
		}
	});
}

void BulletManager::updateAllCustom(std::function<void(Bullet&)> callback) {
	pool->forEachActive(callback);
}