#pragma once
#include "PhysicsComponent.h"
#include "Fighter.h"
#include "Messages_defs.h"

class FigtherFighterCollision : public PhysicsComponent
{
public:
	FigtherFighterCollision();
	~FigtherFighterCollision(); 
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message & msg);

protected:
	GameObject* fighter0_ = nullptr;
	GameObject* fighter1_ = nullptr;
};