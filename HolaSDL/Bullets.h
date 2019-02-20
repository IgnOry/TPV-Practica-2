#pragma once
#include "GameObjectPool.h"
#include "Bullet.h"
#include "NaturalMovePC.h"
#include "ImageGC.h"
#include "DeactivateOnBorderExit.h"

class Bullets : public GameObjectPool<Bullet, 10> {
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();
	void createBullets(int n);
	// 
	
private:
	// components for Bullet
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;

};

