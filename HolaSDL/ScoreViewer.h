#pragma once
#include "GraphicsComponent.h"

class ScoreViewer: public GraphicsComponent
{
public:
	ScoreViewer();
	~ScoreViewer();
	virtual void render(Container* c, Uint32 time);
};

