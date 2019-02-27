#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer()
{
}


LivesViewer::~LivesViewer()
{
}

void LivesViewer::render(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	// draw score
	Texture score(gm->getGame()->getRenderer(),
		to_string(gm->getLives()),
		*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x111122ff) });


	score.render(gm->getGame()->getRenderer(),
		gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, 10); //Coordenadas
}