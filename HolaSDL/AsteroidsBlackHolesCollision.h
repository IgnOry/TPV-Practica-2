#pragma once
#include "PhysicsComponent.h"
#include "BlackHole.h"
#include "Collisions.h"
#include "Messages_defs.h"
#include "Asteroid.h"
class AsteroidsBlackHolesCollision :
	public PhysicsComponent
{
public:
	AsteroidsBlackHolesCollision();
	virtual ~AsteroidsBlackHolesCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message & msg);
private:
	GameObject* fighter_ = nullptr;
	const vector<BlackHole*>* blackHoles_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;


};

