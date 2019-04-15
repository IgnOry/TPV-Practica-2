#pragma once

#include <vector>
#include "Vector2D.h"
#include "GameObject.h"

// you can replace these lines by corresponding
// includes once the classes are defined

class Asteroid;
class Bullet;
class BlackHole;

namespace msg {

struct Message {
	Message(msg::MessageType type, msg::ObjectId sender, msg::ObjectId destination) :
			type_(type), sender_(sender), destination_(destination) {
	}

	msg::MessageType type_;
	msg::ObjectId sender_;
	msg::ObjectId destination_;
};

struct Shoot: public msg::Message {
	Shoot(msg::ObjectId sender, msg::ObjectId destination, Vector2D pos, Vector2D dir, int type) :
	Message(msg::FIGHTER_SHOOT, sender, destination), pos_(pos), dir_(dir), type_(type) {
	}

	Vector2D pos_;
	Vector2D dir_;
	int type_;
};

struct BulletAsteroidCollision: public msg::Message {
	BulletAsteroidCollision(msg::ObjectId sender, msg::ObjectId destination, Bullet* bullet, Asteroid* asteroid) :
	Message(msg::BULLET_ASTEROID_COLLISION, sender, destination), bullet_(bullet), asteroid_(asteroid)  {
	}

	Bullet* bullet_;
	Asteroid* asteroid_;
};

struct BulletsBlackHoleCollision : public msg::Message {
	BulletsBlackHoleCollision(msg::ObjectId sender, msg::ObjectId destination, Bullet* bullet, BlackHole* blackHole) :
		Message(msg::BULLET_BLACKHOLE_COLLISION, sender, destination), bullet_(bullet), blackHole_(blackHole) {
	}

	Bullet* bullet_;
	BlackHole* blackHole_;
};

struct FighterAsteroidCollisionMsg: public msg::Message {
	FighterAsteroidCollisionMsg(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter, Asteroid* asteroid) :
	Message(msg::FIGHTER_ASTEROID_COLLISION, sender, destination), fighter_(fighter), asteroid_(asteroid)  {
	}

	GameObject* fighter_;
	Asteroid* asteroid_;
};

struct AsteroidBlackHoleCollisionMsg : public msg::Message {
	AsteroidBlackHoleCollisionMsg(msg::ObjectId sender, msg::ObjectId destination, Asteroid* asteroid, BlackHole* blackHole, GameObject* fighter) :
		Message(msg::ASEROID_BLACKHOLE_COLLISION, sender, destination), asteroid_(asteroid), blackHole_(blackHole), fighter_(fighter) {
	}

	Asteroid* asteroid_;
	BlackHole* blackHole_;
	GameObject* fighter_;
};

struct FighterBlackHoleCollisionMsg : public msg::Message {
	FighterBlackHoleCollisionMsg(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter, BlackHole* blackHole) :
		Message(msg::FIGHTER_BLACKHOLE_COLLISION, sender, destination), fighter_(fighter), blackHole_(blackHole) {
	}

	GameObject* fighter_;
	BlackHole* blackHole_;
};

struct AsteroidDestroyed: public msg::Message {
	AsteroidDestroyed(msg::ObjectId sender, msg::ObjectId destination, int points) :
	Message(msg::ASTEROID_DESTROYED, sender, destination), points_(points)  {
	}

	int points_;
};

struct FighterInfo: public msg::Message {
	FighterInfo(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter) :
	Message(msg::FIGHTER_INFO, sender, destination), fighter_(fighter)  {
	}

	GameObject*  fighter_;
};

struct BulletsInfoMsg: public msg::Message {
	BulletsInfoMsg(msg::ObjectId sender, msg::ObjectId destination, const std::vector<Bullet*>* bullets) :
	Message(msg::BULLETS_INFO, sender, destination), bullets_(bullets)  {
	}
	const std::vector<Bullet*>*  bullets_;
};

struct AsteroidsInfo: public msg::Message {
	AsteroidsInfo(msg::ObjectId sender, msg::ObjectId destination, const std::vector<Asteroid*>* asteroids) :
	Message(msg::ASTEROIDS_INFO, sender, destination), asteroids_(asteroids)  {
	}
	const std::vector<Asteroid*>*  asteroids_;
};
struct BlackHolesInfo : public msg::Message {
	BlackHolesInfo(msg::ObjectId sender, msg::ObjectId destination, const std::vector<BlackHole*>* blackHoles) :
		Message(msg::BLACKHOLES_INFO, sender, destination), blackHoles_(blackHoles) {
	}
	const std::vector<BlackHole*>*  blackHoles_;
};
};
