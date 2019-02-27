#include "DeactivateOnBorderExit.h"



DeactivateOnBorderExit::DeactivateOnBorderExit()
{
}


DeactivateOnBorderExit::~DeactivateOnBorderExit()
{
}

void DeactivateOnBorderExit::update(Container * c, Uint32 time)
{
	if (c->getPosition().getX() > 800 || c->getPosition().getX() < 0 || c->getPosition().getY() > 600 || c->getPosition().getX() < 0) {
		cout << "bala desactivada   ";
		c->setActive(false);
	}
}

void DeactivateOnBorderExit::addBullet()
{
}
