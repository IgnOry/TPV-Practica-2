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
	setId(msg::ObjectId::Fighter);
}

Fighter::~Fighter()
{
}

void Fighter::receive(const void* senderObj, const msg::Message& msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		globalSend(this,msg::FighterInfo(getId(), msg::Broadcast ,this));
		break; 
	case msg::ROUND_START:
		setPosition(Vector2D(this->getGame()->getWindowHeight() / 2 - this->width_, this->getGame()->getWindowHeight() / 2 - this->height_));
		setVelocity(Vector2D(0, 0));
		setActive(true);
		break;
	case msg::ROUND_OVER:
		setActive(false);
		break;
	}
}
