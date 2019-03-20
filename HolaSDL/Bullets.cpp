#include "Bullets.h"


Bullets::Bullets(SDLGame * game):GameObjectPool(game),
bulletImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)), naturalMove_(), deactivate_()
{
	game_ = game;

	vector<Bullet*> bullets = getAllObjects();

	for (Bullet* b : bullets) {
		b->addC(&bulletImage_);
		b->addC(&naturalMove_);
	}
}

Bullets::~Bullets()
{
}

void Bullets::createBullets(int n, Vector2D dir, Vector2D pos_)
{
	Bullet *b = getUnusedObject();

	if (b != nullptr)
	{
  		b->setActive(true);
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0, 1);


		b->setHeight(5);
		b->setWidth(1);
		b->setPosition(pos_ - Vector2D(this->getWidth() / 2, this->getHeight() / 2));
		b->setVelocity(dir * 5);
		b->setRotation(Vector2D(0, -1).angle(dir));
		b->addC(&deactivate_);
	}
}

void Bullets::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		globalSend(this, msg::BulletsInfoMsg(getId(), msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		break;
	case msg::BULLET_ASTEROID_COLLISION:
		static_cast<const msg::BulletAsteroidCollision&>(msg).bullet_->setActive(false);
		break;
	case msg::FIGHTER_SHOOT:
		
		createBullets(1, static_cast<const msg::Shoot&>(msg).dir_,	static_cast<const msg::Shoot&>(msg).pos_);

		break;
	}
}

