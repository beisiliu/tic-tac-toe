// key pressed

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

enum keyPassedSurface
{
    DEFAULT_SURFACE,
    UP_SURFACE,
    DOWN_SURFACE,
    RIGHT_SURFACE,
    LEFT_SURFACE,
    TOTAL_SURFACE
};

SDL_Window* gWindow;
SDL_Surface* gSurface;
SDL_Surface* gKeySurface[TOTAL_SURFACE];

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Surface* loadImg(const char* imgPath);
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

SDL_Surface* loadImg(const char* imgPath)
{
    SDL_Surface* tmpSurface = SDL_LoadBMP(imgPath);
    if (tmpSurface == nullptr )
    {
        printf("load img error, PATH: %s, Error: %s ", imgPath, SDL_GetError());
        return nullptr;
    }
    return tmpSurface;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example03", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        gKeySurface[DEFAULT_SURFACE] = loadImg("aaaa.png");
        gKeySurface[UP_SURFACE] = loadImg("aaaa.png");
        gKeySurface[DOWN_SURFACE] = loadImg("aaaa.png");
        gKeySurface[RIGHT_SURFACE] = loadImg("aaaa.png");
        gKeySurface[LEFT_SURFACE] = loadImg("aaaa.png");
      
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
                if(e.type == SDL_KEYDOWN)
                {
                    if( e.key.keysym.sym == SDLK_UP)
                    {
                        SDL_BlitSurface(gKeySurface[UP_SURFACE], nullptr, gSurface, nullptr);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                    if( e.key.keysym.sym == SDLK_DOWN)
                    {
                        SDL_BlitSurface(gKeySurface[DOWN_SURFACE], nullptr, gSurface, nullptr);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                    if( e.key.keysym.sym == SDLK_RIGHT)
                    {
                        SDL_BlitSurface(gKeySurface[RIGHT_SURFACE], nullptr, gSurface, nullptr);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                    if( e.key.keysym.sym == SDLK_LEFT)
                    {
                        SDL_BlitSurface(gKeySurface[LEFT_SURFACE], nullptr, gSurface, nullptr);
                        SDL_UpdateWindowSurface(gWindow);
                    }
                }
                else
                {
                    SDL_BlitSurface(gKeySurface[DEFAULT_SURFACE], nullptr, gSurface, nullptr);
                    SDL_UpdateWindowSurface(gWindow);                   
                }
                
            }
        }
    }

    close();
}
