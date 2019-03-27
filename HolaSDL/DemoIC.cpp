#include "DemoIC.h"

#include "DemoContainer.h"
DemoIC::DemoIC(SDL_Keycode ctrlKey)
{
}

DemoIC::~DemoIC() {
}

void DemoIC::handleInput(Container* c, Uint32 time) 
{
  if (InputHandler::getInstance()->isAnyKeyDown())
  {
      if (InputHandler::getInstance()->isKeyDown(ctrlKey_))
        static_cast<DemoContainer*>(c)->reset();
  }
}
