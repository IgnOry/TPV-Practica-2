#pragma once

#include "Vector2D.h"

class EggInterface
{
public:
	/*EggInterface();
	~EggInterface();*/

	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc) = 0;
};

