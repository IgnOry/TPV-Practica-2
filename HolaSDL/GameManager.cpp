#include "GameManager.h"


GameManager::GameManager(SDLGame * game) : running_(false), gameOver_(true), score_(0), lives_(maxLives_), winner_(0)
{
	game_ = game;
	addC(&gameCtrl_);
	addC(&scoreView_);
	addC(&gameStatusView_);
	addC(&livesViewer_);
	addC(&fighterAsteroidCollision_);
	addC(&bulletsAsteroidsCollision_);
}

GameManager::~GameManager()
{
}

bool GameManager::getRunning()
{
	return running_;
}

int GameManager::getScore()
{
	return score_;
}

int GameManager::getLives()
{
	return lives_;
}

int GameManager::getWinner()
{
	return winner_;
}

bool GameManager::getGameOver()
{
	return gameOver_;
}
