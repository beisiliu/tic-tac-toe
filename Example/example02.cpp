// load image

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

SDL_Window* gWindow;
SDL_Surface* gSurface;
SDL_Surface* gHelloWorld;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadImg(const char* imgPath);
void close();

bool init(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
    {
        printf("SDL Init Error: %s \n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow(title, x, y, w, h, flags);
    if ( gWindow == nullptr )
    {
        printf("SDL Create Window Error: %s \n", SDL_GetError());
        return false;
    }

    gSurface = SDL_GetWindowSurface( gWindow );
    if ( gSurface == nullptr )
    {
        printf("SDL GetWindowSurface Error: %s \n", SDL_GetError());
        return false;
    }

    return true;

}

bool loadImg(const char* imgPath)
{
    gHelloWorld = SDL_LoadBMP(imgPath);
    if (gHelloWorld == nullptr )
    {
        printf("load img error, PATH: %s, Error: %s ", imgPath, SDL_GetError());
        return false;
    }
    return true;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        if ( !loadImg("helloWorld.bmp") )
        {        
            printf("Load Image Error : ");
            return 1;
        }

        SDL_Event e;
        bool isRunning = true;
        while(isRunning)
        {
            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                
            }

            SDL_BlitSurface(gHelloWorld, nullptr, gSurface, nullptr);
            SDL_UpdateWindowSurface( gWindow );
        }
    }
    close();
}
