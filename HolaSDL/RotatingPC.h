#pragma once
#include "PhysicsComponent.h"

class RotatingPC: public PhysicsComponent
{
public:
	RotatingPC(double angle);
	~RotatingPC();
	virtual void update(Container* c, Uint32 time);
private:
	double angle_;
};

