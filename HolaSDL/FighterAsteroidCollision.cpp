#include "FighterAsteroidCollision.h"
#include "GameManager.h"
#include "Messages_defs.h"


FighterAsteroidCollision::FighterAsteroidCollision()
{
}


FighterAsteroidCollision::~FighterAsteroidCollision()
{
}

void FighterAsteroidCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (fighter_ != nullptr || asteroids_ != nullptr)
	{
		for (int i = 0; i < asteroids_->size(); i++) {
			if (gm->getRunning() && asteroids_->at(i)->isActive() && fighter_->isActive() && Collisions::collidesWithRotation(asteroids_->at(i), fighter_))
			{
				c->globalSend(c, msg::FighterAsteroidCollisionMsg(c->getId(), msg::Broadcast, fighter_, asteroids_->at(i)));
			}
		}
	}
}
