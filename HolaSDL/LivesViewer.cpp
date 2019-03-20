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

	Texture lives(gm->getGame()->getRenderer(), "resources/images/heart.png");

	int i = gm->getLives();
	// draw score
	
	for (int j = 0; j < i; j++)
		lives.render(gm->getGame()->getRenderer(),	10 + 15 * j, 10);
}