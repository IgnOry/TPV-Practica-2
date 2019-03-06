#pragma once
#include "InputComponent.h"


class GameManager;

class GameCtrlIC : public InputComponent
{
public:
	GameCtrlIC();
	virtual ~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
	virtual void receive(const void * senderObj, const msg::Message & msg);
protected:
};

