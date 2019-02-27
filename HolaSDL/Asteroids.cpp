#include "Asteroids.h"



Asteroids::Asteroids(SDLGame* game): GameObjectPool(game),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), naturalMove_(), rotating_(5), showUpAtOppositeSide_()
{
	game_ = game;
	
	createAsteroids(5);
	vector<Asteroid*> asteroids = getAllObjects();
		
	for (Asteroid* a : asteroids) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&rotating_);
		a->addC(&showUpAtOppositeSide_);
		a->setPosition(Vector2D(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 750), getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 550)));
		a->setVelocity(Vector2D(double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100, double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100))/100));

	}
}


Asteroids::~Asteroids()
{
}

void Asteroids::createAsteroids(int n)
{
	for (int i = 0; i < n; i++)
	{
		Asteroid *a = getUnusedObject();
		a->setActive(true);
		cout << "Asteroide creado" << endl;
	}
}


