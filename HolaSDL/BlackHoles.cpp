#include "BlackHoles.h"
#include "Logger.h"
#include <sstream>
#include "GameManager.h"  //POSIBLE ERROR DE DEPENDENCIA!!!


BlackHoles::BlackHoles(SDLGame * game) : GameObjectPool(game),
blackHoleImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)), rotating_(5)
{
  for (BlackHole* b : getAllObjects()) {
    b->addC(&blackHoleImage_);
    b->addC(&rotating_);
  }
}

void BlackHoles::createBlackHoles(int n, int width_, int height_)
{
  for (int i = 0; i < n; i++)
  {
    BlackHole *b = getUnusedObject();

    if (b != nullptr)
    {
      b->setActive(true);

      double x = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
      double y = this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);

      // coloca los agujeros negros evitando la zona donde empieza el caza
      if (x <= 2)
        x = x * 100 + this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 50);
      else
        x = x * 200 + this->getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 50);


      if (y <= 2)
        y = y * 50;
      else
        y = y * 150;

      Vector2D pos = Vector2D(x, y);
      b->setPosition(pos);

      b->setVelocity(Vector2D(0, 0));
      b->setWidth(width_);
      b->setHeight(height_);

      Logger::getInstance()->log([pos]() {
        stringstream s;
        s << "New Black Hole: " << pos;
        return s.str();
      });
    }
  }
}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg)
{
  Container::receive(senderObj, msg);

  switch (msg.type_) {
 /* case msg::GAME_START:
    globalSend(this, msg::AsteroidsInfo(getId(), msg::Broadcast, &getAllObjects()));
    break;*/
  case msg::ROUND_START:
    createBlackHoles((round_+1)*  2, 50, 50);
    break;
  case msg::ROUND_OVER:
    round_++;
    deactiveAllObjects();
    break;
  case msg::BULLET_BLACKHOLE_COLLISION:

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
  case ASTEROID
}

BlackHoles::~BlackHoles()
{
}
