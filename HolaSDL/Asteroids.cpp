#include "Asteroids.h"
#include "Logger.h"
#include <sstream>


Asteroids::Asteroids(SDLGame* game): GameObjectPool(game),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(5), showUpAtOppositeSide_()
{		
	for (Asteroid* a : getAllObjects()) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&rotating_);
		a->addC(&showUpAtOppositeSide_);
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
        Vector2D pos = Vector2D(x,y);
        a->setPosition(pos);

        Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
        Vector2D v = (c - a->getPosition()).normalize() * (this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 20) / 20.0) * velocity_;

        a->setVelocity(v);

        a->setGenerations(generation);

        a->setWidth(width_);
        a->setHeight(height_);

		Logger::getInstance()->log([pos, v]() {
			stringstream s;
			s << "New asteroid: " << pos << " " << v;
			return s.str();
		});
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
		createAsteroidsRound(5, 3, 30, 30, 2);
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		break;
	case msg::BULLET_ASTEROID_COLLISION:

		static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->setActive(false);
		
		globalSend(this, msg::AsteroidDestroyed(getId(), msg::Broadcast, 4 - static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration()));

		if (static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration() > 1)
			createAsteroids(2, static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getGeneration() - 1, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getWidth() * 0.75, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getHeight() * 0.75, 
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getVelocity() * 1.1,
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getPosition().getX(),
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getPosition().getY());
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, 3);

   		if (allObjectsNotActive())
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, this->getId(), msg::Broadcast));

		break;
	case msg::ASEROID_BLACKHOLE_COLLISION:
		
		// Hay que hacer mover al asteroide a una posición ranmon, peor que no sea la del fighter, para ello hay que acceder a la posición del fighter
		tpAsteroid(static_cast<const msg::AsteroidBlackHoleCollisionMsg&>(msg).asteroid_, static_cast<const msg::AsteroidBlackHoleCollisionMsg&>(msg).fighter_->getPosition()
		+ Vector2D(static_cast<const msg::AsteroidBlackHoleCollisionMsg&>(msg).fighter_->getWidth(),static_cast<const msg::AsteroidBlackHoleCollisionMsg&>(msg).fighter_->getHeight()));
		break;
	}
}

void Asteroids::tpAsteroid(Asteroid* asteroid, Vector2D fighterPos) {
	double x;
	double y;
	do {
		x = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, this->getGame()->getWindowWidth());
		y = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, this->getGame()->getWindowHeight());
	} while ((x < fighterPos.getX() + 100 && x > fighterPos.getX() - 100) && (y < fighterPos.getY() + 75 && y > fighterPos.getY() - 75));

	asteroid->setPosition(Vector2D(x, y));
}

