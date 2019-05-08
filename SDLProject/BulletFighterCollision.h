#pragma once
#include "PhysicsComponent.h"
#include "Bullet.h"
#include "Fighter.h"
#include "Messages_defs.h"

class BulletFighterCollision: public PhysicsComponent
{
public:
	BulletFighterCollision();
	~BulletFighterCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message & msg);

protected:
	GameObject* fighter0_ = nullptr;
	//GameObject* fighter1_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
};

