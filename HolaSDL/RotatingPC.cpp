#include "RotatingPC.h"



RotatingPC::RotatingPC(double angle): angle_(angle)
{
}


RotatingPC::~RotatingPC()
{
}

void RotatingPC::update(Container* c, Uint32 time)
{
	c->setRotation(angle_);
}
