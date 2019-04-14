#pragma once
#include "PhysicsComponent.h"
#include "BlackHole.h"
#include "Bullet.h"
#include "Messages_defs.h"

class BulletsBlackHolesCollision : public PhysicsComponent
{
public:
	BulletsBlackHolesCollision();
	virtual ~BulletsBlackHolesCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message & msg);

protected:
	const vector<BlackHole*>* blackHoles_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
};

