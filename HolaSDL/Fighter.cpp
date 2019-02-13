#include "Fighter.h"

Fighter::Fighter(SDLGame * game, double width, double height, Vector2D position):
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	naturalMove_(),
	oppositeSide_(),
	rotation_(SDLK_LEFT, SDLK_RIGHT, 5),
	thrust_(SDLK_UP, 0.5, 2.0),
	reduceSpeed_(0.995),
	normalGun_ (SDLK_SPACE)
{
	game_ = game;
	width_ = width;
	height_ = height;
	position_ = position;

	addC(&fighterImage_);
	addC(&naturalMove_);
	addC(&oppositeSide_);
	addC(&rotation_);
	addC(&thrust_);
	addC(&reduceSpeed_);
	addC(&normalGun_);
}

Fighter::~Fighter()
{
}
