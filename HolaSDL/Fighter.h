#ifndef _AA
#define _AA

#include "BulletsShooter.h"
#include "GameObject.h"
#include "BulletInterface.h"
/*
 *
 */
class Fighter : public GameObject {
public:
	Fighter(SDLGame* game, BulletInterface* bs);
	virtual ~Fighter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	Texture* fighterTexture_;
	SDL_Rect clip_;
	BulletInterface* bs_;
};

#endif _AA
