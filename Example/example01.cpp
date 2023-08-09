// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
    // the window will be rendering to
    SDL_Window* window = nullptr;

    // the surface contained by the window
    SDL_Surface* screenSurface = nullptr;

    // Initialize SDL
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf( "SDL could not initialize ! SDL Error : %s \n", SDL_GetError() );
    }
    else
    {
        // Create Window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( window == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            // get window surface
            screenSurface = SDL_GetWindowSurface( window );
            if ( screenSurface == nullptr )
            {
                printf( "screenSurface could not be created! SDL_Error: %s\n", SDL_GetError() );
            }
            else
            {
                //fill the surface white
                SDL_FillRect(screenSurface, nullptr, SDL_MapRGB ( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

                // update the surface
                SDL_UpdateWindowSurface( window );

                // Hack to get window to stay up
                SDL_Event e; 
                bool quit = false; 
                while( quit == false )
                { 
                    while( SDL_PollEvent( &e ) )
                    { 
                        if( e.type == SDL_QUIT ) quit = true;
                    } 
                
                }

            }
        }

    }

    // Destroy the window
    SDL_DestroyWindow( window );
    
    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}