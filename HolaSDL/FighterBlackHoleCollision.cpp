#include "FighterBlackHoleCollision.h"
#include "GameManager.h"
#include "Messages_defs.h"


FighterBlackHoleCollision::FighterBlackHoleCollision()
{
}


FighterBlackHoleCollision::~FighterBlackHoleCollision()
{
}

void FighterBlackHoleCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (fighter_ != nullptr || blackHoles_ != nullptr)
	{
		for (int i = 0; i < blackHoles_->size(); i++) {
			if (gm->getRunning() && blackHoles_->at(i)->isActive() && fighter_->isActive() && Collisions::collidesWithRotation(blackHoles_->at(i), fighter_))
				c->globalSend(this, msg::FighterBlackHoleCollisionMsg(c->getId(), msg::Broadcast, fighter_, blackHoles_->at(i)));
		}
	}

}

void FighterBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	
	switch (msg.type_) {
	case msg::BLACKHOLES_INFO:
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}
