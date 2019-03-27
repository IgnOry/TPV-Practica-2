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

void GameManager::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		gameOver_ = false;
		winner_ = 0;
		lives_ = maxLives_;
    score_ = 0;
		break;
	case msg::ROUND_START:
		running_ = true;
		getGame()->getServiceLocator()->getAudios()->playMusic(Resources::ImperialMarch, -1);
		break;
	case msg::ASTEROID_DESTROYED:
		score_ += static_cast<const msg::AsteroidDestroyed&>(msg).points_;
		break;
	case msg::NO_MORE_ASTEROIDS:
		running_ = false;
		gameOver_ = true;
		winner_ = 2;
		this->getGame()->getServiceLocator()->getAudios()->pauseMusic();
		globalSend(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));
		globalSend(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));

		break;
	case msg::FIGHTER_ASTEROID_COLLISION:
		this->getGame()->getServiceLocator()->getAudios()->haltMusic(); //mirar channels


		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, 2);


		running_ = false;

		globalSend(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));

		if (lives_ == 0)
		{
			gameOver_ = true;
			winner_ = 1;
			globalSend(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));
		}

		else
			lives_ += -1;

		break;
	}
}
