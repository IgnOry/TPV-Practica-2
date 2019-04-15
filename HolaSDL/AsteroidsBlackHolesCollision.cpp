#include "AsteroidsBlackHolesCollision.h"
#include "GameManager.h"



AsteroidsBlackHolesCollision::AsteroidsBlackHolesCollision()
{
}


AsteroidsBlackHolesCollision::~AsteroidsBlackHolesCollision()
{
}

void AsteroidsBlackHolesCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (asteroids_ != nullptr || blackHoles_ != nullptr)
	{
		for (int i = 0; i < blackHoles_->size(); i++) {
			for (int j = 0; j < asteroids_->size(); j++) {
				if (gm->getRunning() && blackHoles_->at(i)->isActive() && asteroids_->at(j)->isActive() &&
					Collisions::collidesWithRotation(blackHoles_->at(i), asteroids_->at(j)))

					c->globalSend(c, msg::AsteroidBlackHoleCollisionMsg(c->getId(), msg::Broadcast, asteroids_->at(j), blackHoles_->at(i),fighter_));
			}
		}
	}
}

void AsteroidsBlackHolesCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::BLACKHOLES_INFO:
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case msg::ASTEROIDS_INFO:
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}

