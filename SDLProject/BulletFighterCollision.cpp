#include "BulletFighterCollision.h"
#include "Collisions.h"
#include "GameManager.h"


BulletFighterCollision::BulletFighterCollision()
{
}


BulletFighterCollision::~BulletFighterCollision()
{
}

void BulletFighterCollision::update(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (bullets0_ != nullptr || fighter0_ != nullptr)
	{
			for (int j = 0; j < bullets0_->size(); j++) {
				if ((gm->getStatus() == GameManager::GameStatus::RUNNING) && bullets0_->at(j)->isActive() && fighter0_->isActive() && fighter1_->isActive())
					if(Collisions::collidesWithRotation(bullets0_->at(j), fighter0_))
						c->globalSend(c, msg::BulletFighterCollision(c->getId(), msg::Broadcast, bullets0_->at(j), fighter0_));
					else if (Collisions::collidesWithRotation(bullets0_->at(j), fighter1_))
						c->globalSend(c, msg::BulletFighterCollision(c->getId(), msg::Broadcast, bullets0_->at(j), fighter1_));
			}
		}
}

void BulletFighterCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::FIGHTER_INFO:
		if (msg.clientId_ == 0)
		{
			fighter0_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
			cout << "caza 0" << msg.clientId_ << endl;
		}
		else
		{
			fighter1_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
			cout << "caza 1" << msg.clientId_ << endl;

		}
		break;
	case msg::BULLETS_INFO:
			bullets0_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
