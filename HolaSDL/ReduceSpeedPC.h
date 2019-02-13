#pragma once
#include "PhysicsComponent.h"

class ReduceSpeedPC:public PhysicsComponent
{
public:
	ReduceSpeedPC(double factor); //entre 0 y 1
	~ReduceSpeedPC();
	virtual void update(Container* c, Uint32 time);

private:
	double factor_;
};

