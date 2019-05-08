#include "FigtherFighterCollision.h"
#include "Collisions.h"
#include "GameManager.h"


FigtherFighterCollision::FigtherFighterCollision()
{
}


FigtherFighterCollision::~FigtherFighterCollision()
{
}

void FigtherFighterCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (fighter0_ != nullptr || fighter1_ != nullptr)
	{
		if ((gm->getStatus() == GameManager::GameStatus::RUNNING) && fighter1_->isActive() && fighter0_->isActive() &&
				Collisions::collidesWithRotation(fighter1_, fighter0_));

			c->globalSend(c, msg::FighterFighterCollisionMsg(c->getId(), msg::Broadcast, fighter1_, fighter0_));
	}
}

void FigtherFighterCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::FIGHTER_INFO:		//REVISAR ESTO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (msg.clientId_ == msg::Fighter_0) {
			fighter0_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
			cout << "figher0 : " << fighter0_ << endl;
		}
		else if (msg.clientId_ == msg::Fighter_1) {
			fighter1_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
			cout << "figher0 : " << fighter0_ << endl;
		}


		break;
	}
}
