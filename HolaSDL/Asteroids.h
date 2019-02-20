#pragma once
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "GameObjectPool.h"
#include "RotatingPC.h"
#include "Asteroid.h"

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
	void createAsteroids(int n);
private:
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};