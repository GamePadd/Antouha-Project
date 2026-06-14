#pragma once

#include "BulletSystem/BulletManager.h"
#include "BulletSystem/BulletPool.h"
#include "GameStructures.h"

struct GameContext {
	Player ply;

	//Bullets

	BulletPool pool;
	BulletManager bullets;

	GameContext() : bullets(nullptr, &pool) {}
};