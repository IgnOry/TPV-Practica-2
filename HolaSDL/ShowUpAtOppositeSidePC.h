#pragma once

#include "Component.h"
#include "PhysicsComponent.h"

class ShowUpAtOppositeSidePC: public PhysicsComponent{
public:
	ShowUpAtOppositeSidePC();
	ShowUpAtOppositeSidePC(bool left, bool right, bool top, bool bot);
	virtual ~ShowUpAtOppositeSidePC();
	virtual void update(Container* c, Uint32 time);

private:
	bool left_;
	bool right_;
	bool top_;
	bool bot_;
};

