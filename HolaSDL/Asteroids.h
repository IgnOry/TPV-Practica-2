#pragma once
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "GameObjectPool.h"
#include "RotatingPC.h"
#include "Asteroid.h"
#include "Messages_defs.h"

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
	void createAsteroids(int n, int generation, int width_, int height_, int velocity_);
	virtual void receive(const void* senderObj, const msg::Message& msg);
private:
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
	//vector<Asteroid*> asteroids;
};