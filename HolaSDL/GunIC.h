#pragma once
#include "InputComponent.h"
#include "Messages_defs.h"
#include "InputHandler.h"

class GunIC : public InputComponent
{
public:
	GunIC(SDL_Keycode key1);
	~GunIC();
	virtual void handleInput(Container* c, Uint32 time);
private:
	SDL_Keycode key1_;

};

