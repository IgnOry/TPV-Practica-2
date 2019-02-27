#include "GameCtrlIC.h"
#include "GameManager.h"
#include "Messages_defs.h"


GameCtrlIC::GameCtrlIC()
{
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	GameManager* gm = static_cast<GameManager*>(c);

	// if any key pressed while not running, we choose a random velocity of the ball
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_BACKSPACE && !gm->getRunning()) {
			if (gm->getGameOver())
				c->globalSend(c, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));

			c->globalSend(c, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
		}
	}
}
