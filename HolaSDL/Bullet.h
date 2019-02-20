#pragma once
#include "Container.h"

class Bullet: public Container
{
public:
	Bullet();
	~Bullet();
	int getPower();
	void setPower(int value);

private:
	int power_;
};

