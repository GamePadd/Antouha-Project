#pragma once

#include "../Framework/FrameworkH.h"

struct Player {
	Ant::Vec2f pos;
	Ant::Vec2f size;

	Ant::Texture* sprite;
};

struct Bullet {
	Ant::Vec2f velocity;
	Ant::Vec2f pos;
	Ant::Vec2f size;
	Ant::Texture* sprite;

	bool active;
};