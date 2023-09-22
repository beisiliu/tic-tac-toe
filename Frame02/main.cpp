#include "Game.h"

int main(int argc, char* argv[])
{
	Game *mainGame = new Game();
	mainGame->gameSetting();
	if(!mainGame->gameInit())
	{
		printf("Game init error \n");
		return 1;
	}
	if(!mainGame->imgInit())
	{
		printf("Img init error \n");
		return 2;
	}

	SDL_Event e;
	while(mainGame->isRunning)
	{
		mainGame->gameEvent(e);
		mainGame->gameUpdate();
		
		SDL_RenderClear(mainGame->gRenderer);
		mainGame->gameRender();
		SDL_RenderPresent(mainGame->gRenderer);
	}

	delete mainGame;
	SDL_Quit();
}