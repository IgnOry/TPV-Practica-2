#pragma once

#include "Vector2D.h"

class BulletInterface
{
public:
	//BulletInterface();
	//~BulletInterface();

	virtual void addBullet(Vector2D pos, Vector2D vel) = 0;
};

