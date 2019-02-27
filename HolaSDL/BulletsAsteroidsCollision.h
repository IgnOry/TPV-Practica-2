#pragma once
#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Bullet.h"

class BulletsAsteroidsCollision: public PhysicsComponent
{
public:
	BulletsAsteroidsCollision();
	~BulletsAsteroidsCollision();
	virtual void update(Container* c, Uint32 time);

protected:
	const vector<Asteroid*>* asteroids_ = nullptr; 
	const vector<Bullet*>* bullets_ = nullptr;
};

