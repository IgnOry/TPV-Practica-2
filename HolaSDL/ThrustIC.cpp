#include "ThrustIC.h"



ThrustIC::ThrustIC(SDL_Keycode key1, double thrust, double speedLimit): key1_(key1), thrust_(thrust),speedLimit_(speedLimit)
{
}


ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time)
{
  if (InputHandler::getInstance()->isAnyKeyDown())
  {
    if (InputHandler::getInstance()->isKeyDown(key1_))
    {
      c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));

      if (c->getVelocity().magnitude() > speedLimit_)
        c->setVelocity(c->getVelocity().normalize()*speedLimit_);
    }
	}
}
