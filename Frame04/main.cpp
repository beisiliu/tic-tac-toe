// check collision
#include "Game.h"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int PRE_FRAME_TIME = 1000 / FPS;
	Uint32 frameStartTime = 0;
	Uint32 frameTime = 0;

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
		frameStartTime = SDL_GetTicks();

		mainGame->gameEvent(e);
		mainGame->gameUpdate();
		
		// bg CL
		SDL_SetRenderDrawColor(mainGame->gRenderer, 255, 255, 255, 255);
		SDL_RenderClear(mainGame->gRenderer);
		mainGame->gameRender();
		SDL_RenderPresent(mainGame->gRenderer);

		frameTime = SDL_GetTicks() - frameStartTime;
		if (frameTime < PRE_FRAME_TIME)
        {
            SDL_Delay(PRE_FRAME_TIME - frameTime);
        }
	}

	delete mainGame;
	SDL_Quit();
}