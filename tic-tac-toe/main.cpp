#include "mainGame.hpp"
#include <fstream>
#include <iostream>

const char* TITLE = "Tic-Tac-Toc";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 300;

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;

int main()
{
    MainGame * mainGame = new MainGame;
    Uint32 frameStart, frameTime;

    if ( !mainGame->gameInit(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN) ) return 1;
    
    while ( mainGame->isGameRunning )
    {
        frameStart = SDL_GetTicks();
        mainGame->handleEvent();
        // scenes01
        if ( mainGame->playerLetter == 0 )
        {
            mainGame->renderer01();
        }

        // scenes02
        if (mainGame->playerLetter != 0)
        {
            mainGame->renderer02();
        }

        // for (int i = 0; i< mainGame->board.size(); ++i)
        // {
        //     std::cout << mainGame->board[i] ;
        // }
        // std::cout << "\n";

        // control frame
        frameTime = SDL_GetTicks() - frameStart;
        if ( frameTime < DELAY_TIME )
        {
            SDL_Delay( (int)(DELAY_TIME - frameTime) );
        }
    }

    delete mainGame;
}
