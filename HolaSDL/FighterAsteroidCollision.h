#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Collisions.h"
#include "Messages_defs.h"

class FighterAsteroidCollision: public PhysicsComponent
{
public:
	FighterAsteroidCollision();
	~FighterAsteroidCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive (Container* c, const msg::Message & msg);

protected:

	GameObject* fighter_ = nullptr; 
	const vector<Asteroid*>* asteroids_ = nullptr;
};

