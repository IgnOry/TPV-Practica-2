#include "Asteroid.h"



Asteroid::Asteroid()
{
	setWidth(20);
	setHeight(20);
}


Asteroid::~Asteroid()
{
}

int Asteroid::getGeneration()
{
	return generations_;
}

void Asteroid::setGenerations(int value)
{
	generations_ = value;
}
