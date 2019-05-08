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

	if (bullets_ != nullptr || fighter0_ != nullptr)
	{
		
			for (int j = 0; j < bullets_->size(); j++) {
				if ((gm->getStatus() == GameManager::GameStatus::RUNNING) && bullets_->at(j)->isActive() && fighter0_->isActive() &&
					Collisions::collidesWithRotation(bullets_->at(j), fighter0_));

					c->globalSend(c, msg::BulletFighterCollision(c->getId(), msg::Broadcast, bullets_->at(j), fighter0_));
			}
		}
}

void BulletFighterCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::FIGHTER_INFO:
		fighter0_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		cout << "figher : " << fighter0_<< endl;
		break;
	case msg::BULLETS_INFO:
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;

		break;
	}
}
