#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, SDL_WINDOW_SHOWN);

    SDL_Event e;
    bool isRunning = true;
    while(isRunning)
    {
        while(SDL_PollEvent( &e )){
            if ( e.type == SDL_QUIT )
            {
                isRunning = false;
            }
        }
    }
    return 0;
}