#include "GunIC.h"


GunIC::GunIC(SDL_Keycode key1): key1_(key1)
{
}

GunIC::~GunIC()
{
}

void GunIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == key1_) {
			Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) +
				Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
			Vector2D d = Vector2D(0, -1).rotate(c->getRotation());

			cout << p << endl;
			cout << d << endl;
		}
	}
}
