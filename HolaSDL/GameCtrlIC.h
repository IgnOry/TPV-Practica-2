#pragma once
#include "InputComponent.h"
#include "InputHandler.h"

class GameManager;

class GameCtrlIC : public InputComponent
{
public:
	GameCtrlIC();
	virtual ~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time);
protected:
};

