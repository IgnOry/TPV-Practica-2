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
				c->globalSend(this, msg::FighterAsteroidCollisionMsg(c->getId(), msg::Broadcast, fighter_, asteroids_->at(i)));
			}
		}
	}
}

void FighterAsteroidCollision::receive(Container * c, const msg::Message & msg)
{

	switch (msg.type_) {
	case msg::ASTEROIDS_INFO:
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}