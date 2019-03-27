#include "GameCtrlIC.h"
#include "GameManager.h"
#include "Messages_defs.h"


GameCtrlIC::GameCtrlIC()
{
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);

  if (InputHandler::getInstance()->isAnyKeyDown())
  {
    if (InputHandler::getInstance()->isKeyDown(SDLK_RETURN) && !gm->getRunning())
      c->globalSend(nullptr, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
    
    c->globalSend(nullptr, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
  }
}

