#pragma once
#include "GameObjectPool.h"
#include "BlackHole.h"
#include "ImageGC.h"
#include "RotatingPC.h"
#include "Messages_defs.h"


class BlackHoles : public GameObjectPool <BlackHole, 50>
{
public:
  BlackHoles(SDLGame* game);
  void createBlackHoles(int n, int width_, int height_);
  virtual void receive(const void* senderObj, const msg::Message& msg);
  virtual ~BlackHoles();
private:
  ImageGC blackHoleImage_;
  RotatingPC rotating_;
  int round_ = 0;
};

