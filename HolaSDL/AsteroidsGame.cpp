#include "AsteroidsGame.h"
#include "Logger.h"

using namespace std;

AsteroidsGame::AsteroidsGame() :
		SDLGame("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_),
		fighterContainer_(this, 50, 50, Vector2D(400,300)), asteroids_(this),
	bullets_(this), 
	manager_(this)

{
	initGame();
}

AsteroidsGame::~AsteroidsGame() {
	closeGame();
}

void AsteroidsGame::initGame() {
	actors_.push_back(&fighterContainer_);
	actors_.push_back(&asteroids_);
	actors_.push_back(&bullets_);
	actors_.push_back(&manager_);

	addObserver(&fighterContainer_);
	addObserver(&asteroids_);
	addObserver(&bullets_);
	addObserver(&manager_);

	Logger::getInstance()->initInstance("log.txt");
}

void AsteroidsGame::closeGame() {
}

void AsteroidsGame::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleInput(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
	//delete Logger::getInstance();
}

void AsteroidsGame::stop() {
	exit_ = true;
}

void AsteroidsGame::handleInput(Uint32 time) {
	InputHandler::getInstance()->update();
	
  if (InputHandler::getInstance()->isAnyKeyDown())
  {
    if (InputHandler::getInstance()->isKeyDown(SDLK_ESCAPE))
      exit_ = true;

    if (InputHandler::getInstance()->isKeyDown(SDLK_f))
    {
      int flags = SDL_GetWindowFlags(window_);
      if (flags & SDL_WINDOW_FULLSCREEN) {
        SDL_SetWindowFullscreen(window_, 0);
      }
      else {
        SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
      }
    }
  }
  
	for (GameObject* o : actors_) {
		o->handleInput(time);
	}
  
}

void AsteroidsGame::update(Uint32 time) {
	for (GameObject* o : actors_) {
		o->update(time);
	}
}

void AsteroidsGame::render(Uint32 time) {
	SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(getRenderer());

	for (GameObject* o : actors_) {
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

