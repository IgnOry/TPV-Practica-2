#pragma once
#include "Container.h"
#include "SDLGame.h"
#include "GameCtrlIC.h"
#include "ScoreViewer.h"
#include "GameStatusViewGC.h"
#include "LivesViewer.h"
#include "FighterAsteroidCollision.h"
#include "FighterBlackHoleCollision.h"
#include "BulletsAsteroidsCollision.h"
#include "BulletsBlackHolesCollision.h"
#include "Messages_defs.h"

class GameManager : public Container {
public: 
	GameManager(SDLGame* game);
	virtual ~GameManager();
	bool getRunning();
	int getScore();
	int getLives();
	int getWinner();
	bool getGameOver();
	virtual void receive(const void * senderObj, const msg::Message & msg);
	// … 

private: 
	// … 
	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_; 
	int lives_;  
	int winner_;  // 0=none, 1=asteroids, 2=fighter 
	void roundEnd();

   // components of GameManager
	GameCtrlIC gameCtrl_;
	ScoreViewer scoreView_;
	GameStatusViewGC gameStatusView_;
	LivesViewer livesViewer_; 
	FighterAsteroidCollision fighterAsteroidCollision_;
	FighterBlackHoleCollision fighterBlackHoleCollision_;
	BulletsAsteroidsCollision bulletsAsteroidsCollision_;
	BulletsBlackHolesCollision bulletsBlackHolesCollision_;
};
