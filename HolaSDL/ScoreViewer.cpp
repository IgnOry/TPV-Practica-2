#include "ScoreViewer.h"
#include "GameManager.h"

ScoreViewer::ScoreViewer()
{
}


ScoreViewer::~ScoreViewer()
{
}

void ScoreViewer::render(Container * c, Uint32 time)
{
	GameManager *gm = static_cast<GameManager*>(c);

	// draw score
	Texture score(gm->getGame()->getRenderer(),
		to_string(gm->getScore()),
		*(gm->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x111122ff) });


	score.render(gm->getGame()->getRenderer(),
		gm->getGame()->getWindowWidth() / 2 - score.getWidth() / 2, 10);  //Coordenadas
}
