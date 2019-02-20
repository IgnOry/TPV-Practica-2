#pragma once
#include "Container.h"

class Asteroid : public Container {
public:
	Asteroid();
	virtual ~Asteroid();
	int getGeneration();
	void setGenerations(int value);
private:
	int generations_;
};

