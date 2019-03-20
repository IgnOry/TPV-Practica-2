#include "BulletsAsteroidsCollision.h"
#include "GameManager.h"


BulletsAsteroidsCollision::BulletsAsteroidsCollision()
{
}


BulletsAsteroidsCollision::~BulletsAsteroidsCollision()
{
}

void BulletsAsteroidsCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (bullets_ != nullptr || asteroids_ != nullptr)
	{
		for (int i = 0; i < asteroids_->size(); i++) {
			for (int j = 0; j < bullets_->size(); j++) {
				if (gm->getRunning() && asteroids_->at(i)->isActive() && bullets_->at(j)->isActive() &&
					Collisions::collidesWithRotation(asteroids_->at(i), bullets_->at(j)))

					c->globalSend(c, msg::BulletAsteroidCollision(c->getId(), msg::Broadcast, bullets_->at(j), asteroids_->at(i)));
			}
		}
	}
}

void BulletsAsteroidsCollision::receive(Container* c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::ASTEROIDS_INFO:
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case msg::BULLETS_INFO:
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
