#include "Asteroid.h"



Asteroid::Asteroid()
{
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
