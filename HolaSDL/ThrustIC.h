#pragma once
#include "InputComponent.h"

class ThrustIC : public InputComponent
{
public:
	ThrustIC(SDL_Keycode key1, double thrust, double speedLimit);
	~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time);

private:
	SDL_Keycode key1_;
	double thrust_;
	double speedLimit_;
};

