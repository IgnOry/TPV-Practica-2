#pragma once

#include "Egg.h"
#include "ObjectPool.h"
#include "EggInterface.h"

/*
 *
 */
class EggsShooter : public ObjectPool<Egg, 20>, public EggInterface {
public:
	EggsShooter(SDLGame* game);
	virtual ~EggsShooter();
	// abstract methods to be implemented in sub-classes
	/*virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);*/
	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc);
private:
	static int const MAX_EGGS=20;
	Egg eggs_[MAX_EGGS];
};

