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
	Texture lives(gm->getGame()->getRenderer(), "Lives: " +
		to_string(gm->getLives()),
		*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x111122ff) });


	lives.render(gm->getGame()->getRenderer(),
		10, 10); //Coordenadas
}