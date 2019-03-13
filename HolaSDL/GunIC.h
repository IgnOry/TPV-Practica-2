#pragma once
#include "InputComponent.h"
#include "Messages_defs.h"

class GunIC : public InputComponent
{
public:
	GunIC(SDL_Keycode key1);
	~GunIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
private:
	SDL_Keycode key1_;

};

