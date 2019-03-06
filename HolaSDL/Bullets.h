#pragma once
#include "GameObjectPool.h"
#include "Bullet.h"
#include "NaturalMovePC.h"
#include "ImageGC.h"
#include "DeactivateOnBorderExit.h"
#include "Messages_defs.h"

class Bullets : public GameObjectPool<Bullet, 10> {
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();
	void createBullets(int n, Vector2D dir, Vector2D pos_);
	virtual void receive(const void* senderObj, const msg::Message& msg);
	// 
	
private:
	// components for Bullet
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;

};

