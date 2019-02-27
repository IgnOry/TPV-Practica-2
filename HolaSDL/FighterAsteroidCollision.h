#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Collisions.h"
//#include "Fighter.h"

class FighterAsteroidCollision: public PhysicsComponent
{
public:
	FighterAsteroidCollision();
	~FighterAsteroidCollision();
	virtual void update(Container* c, Uint32 time);

protected:

	GameObject* fighter_ = nullptr; 
	const vector<Asteroid*>* asteroids_ = nullptr;
};

