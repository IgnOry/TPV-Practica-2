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

	if (!gm->getRunning())
	{
		if (gm->getWinner() == 1) //winner = asteroids
		{
			Texture winner(gm->getGame()->getRenderer(),
				"Game Over - Asteroids Win",
				*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x111122ff) });

			winner.render(gm->getGame()->getRenderer(),
				gm->getGame()->getWindowWidth() / 2 - winner.getWidth() / 2, gm->getGame()->getWindowHeight() / 3 - winner.getHeight()); //Coordenadas
		}
		else if (gm->getWinner() == 2)//winner = player
		{
			Texture winner(gm->getGame()->getRenderer(),
				"Game Over - Player Wins",
				*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x111122ff) });

			winner.render(gm->getGame()->getRenderer(),
				gm->getGame()->getWindowWidth() / 2 - winner.getWidth() / 2, gm->getGame()->getWindowHeight() / 3 - winner.getHeight()); //Coordenadas
		}
		// draw score

		if (gm->getGameOver())
		{
			Texture restart(gm->getGame()->getRenderer(),
				"Press ENTER to Start a New Game",
				*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x111122ff) });

			restart.render(gm->getGame()->getRenderer(),
				gm->getGame()->getWindowWidth() / 2 - restart.getWidth() / 2, gm->getGame()->getWindowHeight() / 2 - restart.getHeight()); //Coordenadas
		}
		else if (gm->getLives() >= 0)
		{
			Texture restart(gm->getGame()->getRenderer(),
				"Press ENTER to Continue",
				*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x111122ff) });

			restart.render(gm->getGame()->getRenderer(),
				gm->getGame()->getWindowWidth() / 2 - restart.getWidth() / 2, gm->getGame()->getWindowHeight() / 2 - restart.getHeight()); //Coordenadas
		}
	}
}
