#pragma once

#include "Bullet.h"
#include "ObjectPool.h"
#include "BulletInterface.h"
/*
 *
 */
class BulletsShooter: public ObjectPool<Bullet,100>, public BulletInterface {
public:
	BulletsShooter(SDLGame* game);
	virtual ~BulletsShooter();
	/*virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);*/
	virtual void addBullet(Vector2D pos, Vector2D vel);
private:
	static int const MAX_BULLETS=100;
	Bullet bullets_[MAX_BULLETS];

};

