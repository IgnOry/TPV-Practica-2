#include "Bullets.h"


Bullets::Bullets(SDLGame * game):GameObjectPool(game),
bulletImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)), naturalMove_(), deactivate_()
{
	game_ = game;
	createBullets(1);
	vector<Bullet*> bullets = getAllObjects();

	for (Bullet* b : bullets) {
		b->addC(&bulletImage_);
		b->addC(&naturalMove_);
		b->setHeight(20);
		b->setWidth(5);
		b->setPosition(Vector2D(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 750), getGame()->getServiceLocator()->getRandomGenerator()->nextInt(50, 550)));
		b->setVelocity(Vector2D(double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100)) / 100, double(getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-100, 100)) / 100));
		b->addC(&deactivate_);

	}
}

Bullets::~Bullets()
{
}

void Bullets::createBullets(int n)
{
	for (int i = 0; i < n; i++)
	{
		Bullet *b = getUnusedObject();
		b->setActive(true);
		cout << "Bala creada" << endl;
	}
}