#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include "ReduceSpeedPC.h"
#include "GunIC.h"
#include "Messages_defs.h"

class Fighter : public Container {
public:
	Fighter(SDLGame * game, double width, double height, Vector2D position);
	virtual ~Fighter();
	virtual void receive(const void* senderObj, const msg::Message& msg);
	// …
private:
	//…
	// components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;
};


