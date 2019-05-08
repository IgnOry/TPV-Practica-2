#pragma once

#include <vector>

#include "ClientInfo.h"
#include "Vector2D.h"
#include "GameObject.h"

// you can replace these lines by corresponding
// includes once the classes are defined

class Asteroid;
class Bullet;

namespace msg {


struct Message {
	Message(msg::MessageType type, msg::ObjectId sender) :
		size_(sizeof(Message)), clientId_(0), type_(type), sender_(sender),destination_(msg::None) {
	}
	Message(msg::MessageType type, msg::ObjectId sender, msg::ObjectId destination, header_t_ size =
			sizeof(Message)) :
			size_(size),
			clientId_(ClientInfo::instance() == nullptr ? 0 : ClientInfo::instance() ->getClientId()),
			type_(type), sender_(sender), destination_(destination)  {
	}
	msg::header_t_ size_;
	int clientId_;
	msg::MessageType type_;
	msg::ObjectId sender_;
	msg::ObjectId destination_;
};

struct Shoot: public msg::Message {
	Shoot(msg::ObjectId sender, msg::ObjectId destination, Vector2D& pos, Vector2D& dir) :
	Message(msg::FIGHTER_SHOOT, sender, destination, sizeof(Shoot)) {
		posX_ = pos.getX();
		posY_ = pos.getY();
		dirX_ = dir.getX();
		dirY_ = dir.getY();
	}

	double posX_;
	double posY_;
	double dirX_;
	double dirY_;
};


// for network game
struct RemoteObjectInfo: public Message {
	RemoteObjectInfo(msg::ObjectId sender, msg::ObjectId destination, const Vector2D& pos, const Vector2D& vel, double rotation) :
			Message(REMOTE_OBJ_INFO, sender, destination, sizeof(RemoteObjectInfo)) {
		posX_ = pos.getX();
		posY_ = pos.getY();
		velX_ = vel.getX();
		velY_ = vel.getY();
		rotation_ = rotation;
	}
	double posX_;
	double posY_;
	double velX_;
	double velY_;
	double rotation_;
};

struct FighterInfo : public msg::Message {
	FighterInfo(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter) :
		Message(msg::FIGHTER_INFO, sender, destination, sizeof(FighterInfo)), fighter_(fighter) {
	}

	GameObject*  fighter_;
};

struct BulletsInfoMsg : public msg::Message {
	BulletsInfoMsg(msg::ObjectId sender, msg::ObjectId destination, const std::vector<Bullet*>* bullets) :
		Message(msg::BULLETS_INFO, sender, destination, sizeof(BulletsInfoMsg)), bullets_(bullets) {
	}
	const std::vector<Bullet*>*  bullets_;
};

struct FighterFighterCollisionMsg : public msg::Message {
	FighterFighterCollisionMsg(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter0, GameObject* fighter1) :
		Message(msg::FIGHTER_FIGHTER_COLLISION, sender, destination, sizeof(BulletsInfoMsg)), fighter0_(fighter0), fighter1_(fighter1) {
	}

	GameObject* fighter0_;
	GameObject* fighter1_;
};

struct BulletFighterCollision : public msg::Message {
	BulletFighterCollision(msg::ObjectId sender, msg::ObjectId destination, Bullet* bullet, GameObject* fighter) :
		Message(msg::BULLET_FIGHTER_COLLISION, sender, destination, sizeof(BulletsInfoMsg)), bullet_(bullet), fighter_(fighter) {
	}

	Bullet* bullet_;
	GameObject* fighter_;
};

struct GameOver : public msg::Message {
	GameOver(msg::ObjectId sender, msg::ObjectId destination, ObjectId id) :
		Message(msg::GAME_OVER, sender, destination, sizeof(BulletsInfoMsg)), id_(id) {
	}

	int id_;
};
};
