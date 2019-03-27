#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game): GameObjectPool(game),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(5), showUpAtOppositeSide_()
{
	//game_ = game;
			
	for (Asteroid* a : getAllObjects()) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&rotating_);
		a->addC(&showUpAtOppositeSide_);
		//a->setPosition(Vector2D(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 750), getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 550)));
		//a->setVelocity(Vector2D(double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100, double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100));
	}

  setId(msg::ObjectId::Asteroids);

}


Asteroids::~Asteroids()
{
}

void Asteroids::createAsteroidsRound(int n, int generation, int width_, int height_, int velocity_)
{
	for (int i = 0; i < n; i++)
	{
     Asteroid *a = getUnusedObject();

      if (a != nullptr)
      {
        a->setActive(true);

        double x = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
        double y = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);


        if (x <= 2)
          x = x * 100 + this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 50);
        else
          x = x * 200 + this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 50);


        if (y <= 2)
          y = y * 50;
        else
          y = y * 150;

        a->setPosition(Vector2D(x, y));

        Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
        Vector2D v = (c - a->getPosition()).normalize() * (this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 20) / 20.0) * velocity_;

        a->setVelocity(v);

        a->setGenerations(generation);

        a->setWidth(width_);
        a->setHeight(height_);
      }
	}
}

void Asteroids::createAsteroids(int n, int generation, int width_, int height_, Vector2D velocity_, double posX, double posY)
{
	for (int i = 0; i < n; i++)
	{
		Asteroid *a = getUnusedObject();
		a->setActive(true);
		
		a->setPosition(Vector2D(posX, posY));
					
		//Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
		Vector2D v = velocity_;

		v = v.rotate(this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 360));

		v = v.rotate(i*10);
		a->setVelocity(v);
	
		a->setGenerations(generation);

		a->setWidth(width_);
		a->setHeight(height_);
	}
}

void Asteroids::receive(const void* senderObj, const msg::Message& msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		globalSend(this, msg::AsteroidsInfo(getId(), msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		createAsteroidsRound(10, 3, 30, 30, 2);
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		break;
	case msg::BULLET_ASTEROID_COLLISION:

		static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->setActive(false);
		//senderobj.getId();
		//static_cast<*Asteroid>(senderObj).
		//senderObj.setActive(false);

		globalSend(this, msg::AsteroidDestroyed(getId(), msg::Broadcast, 4 - static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration()));

		if (static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration() > 1)
			createAsteroids(2, static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration() - 1, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getWidth() * 0.75, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getHeight() * 0.75, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getVelocity() * 1.1,
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getPosition().getX(),
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getPosition().getY());

		if (&getAllObjects() == 0)
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, this->getId(), msg::Broadcast));

		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, 3);

		break;
	}
}


