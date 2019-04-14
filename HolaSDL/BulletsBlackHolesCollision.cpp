#include "BulletsBlackHolesCollision.h"
#include "GameManager.h"


BulletsBlackHolesCollision::BulletsBlackHolesCollision()
{
}


BulletsBlackHolesCollision::~BulletsBlackHolesCollision()
{
}

void BulletsBlackHolesCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (bullets_ != nullptr || blackHoles_ != nullptr)
	{
		for (int i = 0; i < blackHoles_->size(); i++) {
			for (int j = 0; j < bullets_->size(); j++) {
				if (gm->getRunning() && blackHoles_->at(i)->isActive() && bullets_->at(j)->isActive() &&
					Collisions::collidesWithRotation(blackHoles_->at(i), bullets_->at(j)))

					c->globalSend(c, msg::BulletsBlackHoleCollision(c->getId(), msg::Broadcast, bullets_->at(j), blackHoles_->at(i)));
			}
		}
	}
}

void BulletsBlackHolesCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::BLACKHOLES_INFO:
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case msg::BULLETS_INFO:
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
