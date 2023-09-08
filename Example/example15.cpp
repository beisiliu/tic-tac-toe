// time

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <stdio.h>
#include <sstream>


const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

// font
TTF_Font* gFont = nullptr;
SDL_Rect gFontRect;
SDL_Texture* gFontTexture = nullptr;
SDL_Color gFontColor = {0, 255, 255};
int fontWidth = 0;
int fontHeight = 0;

// time
Uint32 startTime = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadFont(char* fontPath);
void time();
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

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if ( gRenderer == nullptr )
    {
        printf("SDL CreateRenderer Error: %s \n", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1)
    {
        printf("TTF Init error: %s \n", TTF_GetError());
        return false;
    }

    return true;

}

bool loadFont(const char* fontPath)
{
    gFont = TTF_OpenFont(fontPath, 18);
    if (gFont == nullptr)
    {
        printf("TTF Open Error %s \n", TTF_GetError());
        return false;
    }

    return true;
}

void time()
{
    std::stringstream sstream;
    sstream << "运行到目前的毫秒数: " << SDL_GetTicks() - startTime ;

    SDL_Surface* tmpSurface = TTF_RenderUTF8_Solid(gFont, sstream.str().c_str(), gFontColor);
    fontWidth = tmpSurface->w;
    fontHeight = tmpSurface->h;

    gFontTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    // 定位
    gFontRect.x = 50; gFontRect.y = 50;
    gFontRect.h = fontHeight; gFontRect.w = fontWidth;  
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}


int main(int argc, char* argv[])
{
    if ( init("example15", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {

        SDL_Event e;
        bool isRunning = true;
        loadFont("ttf/font01.ttf");
        while(isRunning)
        {
            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
                {
                    startTime = SDL_GetTicks();
                }
            }

            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer, gFontTexture, nullptr, &gFontRect);
            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
