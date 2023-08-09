
// Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// the window will be rendering to
SDL_Window* gWindow = nullptr;

// the surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

// the image we will load and show on the screen
SDL_Surface* gHelloWorld = nullptr;

bool init()
{
    // initialization flag
    bool success = true;

    // Initialize SDL
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf( "SDL could not initialize ! SDL Error : %s \n", SDL_GetError() );
        success = false;
    }
    else
    {
        // Create Window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( gWindow == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            // Create Surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
            if ( gScreenSurface == nullptr )
            {
                printf( "gScreenSurface could not be created! SDL_Error: %s\n", SDL_GetError() );
                success = false;
            }
        }
    }
    return success;
}

bool loadMedia()
{
    // initialization flag
    bool success = true;

    // load image
    gHelloWorld = SDL_LoadBMP("hello_world.bmp");
    if ( gHelloWorld == nullptr )
    {
        printf( "Unable to load image %s! \n", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    // deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = nullptr;

    // destroy the window
    SDL_DestroyWindow ( gWindow );
    gWindow = nullptr;

    SDL_Quit();
}


int main(int argc, char* argv[])
{
    if ( !init() )
    {
        printf( "Failed to initialize \n" );
    }
    else
    {
        if ( !loadMedia() )
        {
            printf( "Failed to load media \n");
        }
        else
        {   
            //apply the image
            SDL_BlitSurface( gHelloWorld, nullptr, gScreenSurface, nullptr );

            //update the surface
            SDL_UpdateWindowSurface( gWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    close();
    return 0;
}