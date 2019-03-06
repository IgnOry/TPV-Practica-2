#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game): GameObjectPool(game),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(5), showUpAtOppositeSide_()
{
	game_ = game;
	
	//createAsteroids(5);
		
	for (Asteroid* a : getAllObjects()) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&rotating_);
		a->addC(&showUpAtOppositeSide_);
		a->setPosition(Vector2D(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 750), getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 550)));
		a->setVelocity(Vector2D(double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100, double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100));
		setId(msg::ObjectId::Asteroids);
	}
}


Asteroids::~Asteroids()
{
}

void Asteroids::createAsteroids(int n, int generation, int width_, int height_, int velocity_)
{
	for (int i = 0; i < n; i++)
	{
		Asteroid *a = getUnusedObject();
		a->setActive(true);
		cout << "Asteroide creado" << endl;
		
		a->setPosition(Vector2D(this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, this->getGame()->getWindowWidth()),
			this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, this->getGame()->getWindowHeight())));
		
		Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
		Vector2D v = (c - position_).normalize() * (this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0) * velocity_;

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
		createAsteroids(10, 3, 20, 20, 1);
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
			static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_->getHeight() * 0.75, 1.1);

		if (&getAllObjects() == 0)
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, this->getId(), msg::Broadcast));

		this->getGame()->getServiceLocator()->getAudios()->playMusic(Resources::Explosion, -1);

		break;
	}
}


