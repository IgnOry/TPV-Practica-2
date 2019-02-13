#include "RotationIC.h"

RotationIC::RotationIC(SDL_Keycode key1, SDL_Keycode key2, double angle): key1_(key1), key2_(key2),angle_(angle)
{
}

RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == key1_) {
			c->setRotation(c->getRotation() + angle_);
		}
		else if (event.key.keysym.sym == key2_) {
			c->setRotation(c->getRotation() - angle_);
		}
	}
}
