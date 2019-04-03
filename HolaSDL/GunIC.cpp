#include "GunIC.h"
#include "Logger.h"
#include <sstream>

GunIC::GunIC(SDL_Keycode key1): key1_(key1)
{
}

GunIC::~GunIC()
{
}

void GunIC::handleInput(Container * c, Uint32 time)
{
  if (InputHandler::getInstance()->isAnyKeyDown())
  {
    if (InputHandler::getInstance()->isKeyDown(key1_))
    {
      Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) +
        Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
      Vector2D d = Vector2D(0, -1).rotate(c->getRotation());

      c->globalSend(c, msg::Shoot(c->getId(), msg::Broadcast, p, d, 0));

      c->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0, 5);

	  Logger::getInstance()->log([p, d]() {
		  stringstream s;
		  s << "Shooting: " << p << " " << d;
		  return s.str();
	  });
    }
  }
}
