#pragma once
#include "InputComponent.h"


class RotationIC: public InputComponent
{
public:
	RotationIC(SDL_Keycode key1, SDL_Keycode key2, double angle);
	~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);

private:
	SDL_Keycode key1_;
	SDL_Keycode key2_; 
	double angle_;
};

