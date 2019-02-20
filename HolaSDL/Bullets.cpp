#include "Bullets.h"


Bullets::Bullets(SDLGame * game):GameObjectPool(game),
bulletImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)), naturalMove_(), deactivate_()
{
	createBullets(1);
}

Bullets::~Bullets()
{
}

void Bullets::createBullets(int n)
{
	for (int i = 0; i < n; i++)
	{
		Bullet *a = getUnusedObject();
		a->setActive(true);
		cout << "Creado bala";
	}
}
