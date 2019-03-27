#include "RotationIC.h"

RotationIC::RotationIC(SDL_Keycode key1, SDL_Keycode key2, double angle): key1_(key1), key2_(key2),angle_(angle)
{
}

RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time)
{
  if (InputHandler::getInstance()->isAnyKeyDown())
  {
    if (InputHandler::getInstance()->isKeyDown(key1_))
      c->setRotation(c->getRotation() + angle_);
    else if (InputHandler::getInstance()->isKeyDown(key2_))
      c->setRotation(c->getRotation() - angle_);
  }
}
