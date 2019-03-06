#include "GameStatusViewGC.h"
#include "GameManager.h"

GameStatusViewGC::GameStatusViewGC()
{
}


GameStatusViewGC::~GameStatusViewGC()
{
}

void GameStatusViewGC::render(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	if (gm->getWinner() == 1) //winner = asteroids
	{
		Texture score(gm->getGame()->getRenderer(),
			"Game Over - Asteroids Win",
			*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x111122ff) });

		score.render(gm->getGame()->getRenderer(),
			gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, gm->getGame()->getWindowHeight()/2 - score.getHeight()); //Coordenadas
	}
	else if (gm->getWinner() == 2)//winner = player
	{
		Texture score(gm->getGame()->getRenderer(),
			"Game Over - Player Wins",
			*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x111122ff) });

		score.render(gm->getGame()->getRenderer(),
			gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, gm->getGame()->getWindowHeight() / 2 - score.getHeight()); //Coordenadas
	}
	// draw score

	if (gm->getGameOver()) 
	{
		Texture score(gm->getGame()->getRenderer(),
			"Press ENTER to Start a New Game",
			*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x111122ff) });

		score.render(gm->getGame()->getRenderer(),
			gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, gm->getGame()->getWindowHeight() / 2 - score.getHeight()); //Coordenadas
	}
	else
	{
		Texture score(gm->getGame()->getRenderer(),
			"Press ENTER to Continue",
			*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x111122ff) });

		score.render(gm->getGame()->getRenderer(),
			gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, gm->getGame()->getWindowHeight() / 2 - score.getHeight()); //Coordenadas
	}

}
