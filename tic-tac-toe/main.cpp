#include "mainGame.hpp"

const char* TITLE = "Tic-Tac-Toc";
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 300;


int main()
{
    if ( !MainGame::pInstance()->gameInit(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN) ) return 1;
    while ( MainGame::pInstance()->isGameRunning )
    {
        MainGame::pInstance()->handleEvent();
        // scenes01
        if ( MainGame::pInstance()->playerLetter == '1' )
        {
            MainGame::pInstance()->renderer01();
        }

        // scenes02
        if (MainGame::pInstance()->playerLetter != '1')
        {
            MainGame::pInstance()->renderer02();
        }

        
    }
}
