#include "Fighter.h"
#include "Messages_defs.h"
#include "ClientInfo.h"

Fighter::Fighter(msg::ObjectId id, SDLGame* game) :
		Container(game), //
		fighterImage_(game->getServiceLocator()->getTextures()->getTexture(
						Resources::Airplanes), { 47, 90, 207, 250 }), normalGun_(
				SDLK_SPACE) {

	setWidth(40);
	setHeight(50);
	setId(id);
	setActive(true);
	addC(&fighterImage_);

	if ((ClientInfo::instance()->getClientId() == 0 && getId() == msg::Fighter_0) || (ClientInfo::instance()->getClientId() == 1 && getId() == msg::Fighter_1)) {
		addC(&naturalMove_);
		addC(&rotation_);
		addC(&oppositeSide_);
		addC(&normalGun_);
		addC(&thrust_);
		addC(&reduceSpeed_);
		addC(&broadcastInfoPC_);
	}
	initFighter();
}

Fighter::~Fighter() {
}

void Fighter::receive(const void* senderObj, const msg::Message& msg) {
	Container::receive(senderObj, msg); // to send to all components

	switch (msg.type_) {
	case msg::REMOTE_OBJ_INFO:
		if (ClientInfo::instance()->getClientId() != msg.clientId_ && getId() == msg.sender_) {
			
			const msg::RemoteObjectInfo& m = static_cast<const msg::RemoteObjectInfo&>(msg);

			setPosition(Vector2D(m.posX_, m.posY_));
			setVelocity(Vector2D(m.velX_, m.velY_));
			setRotation(m.rotation_);
		}

		break;

	default:
		break;
	}
}

void Fighter::initFighter() {
	setVelocity(Vector2D(0.0, 0.0));
	if (getId() == msg::Fighter_0)
		setPosition(Vector2D(getGame()->getWindowWidth() / 2 - getWidth() / 2,	getGame()->getWindowHeight() / 2 - getHeight() / 2));
	else if (getId() == msg::Fighter_1)
		setPosition(Vector2D(getGame()->getWindowWidth() / 2 + getWidth() / 2, getGame()->getWindowHeight() / 2 + getHeight() / 2));
}

