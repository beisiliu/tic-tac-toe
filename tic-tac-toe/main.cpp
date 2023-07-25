#include "mainGame.hpp"

const char* TITLE = "Tic-Tac-Toc";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 300;

MainGame * mainGame;
int main()
{
    mainGame = new MainGame;
    if ( !mainGame->gameInit(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN) ) return 1;
    
    while ( mainGame->isGameRunning )
    {
        mainGame->handleEvent();
        // scenes01
        if ( mainGame->playerLetter == '1' )
        {
            mainGame->renderer01();
        }

        // scenes02
        if (mainGame->playerLetter != '1')
        {
            mainGame->renderer02();
        }
    }
    delete mainGame;
}
