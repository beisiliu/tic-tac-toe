// time adv *

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
TTF_Font *gFont;
SDL_Rect dstRectFont;
SDL_Texture* gFontTexture;
int fontWidth = 0;
int fontHeight = 0;
SDL_Color fontColor = {255, 0, 0};

// time
Uint32 startTime = 0;
bool isStart = false;
int loopCount = 0;

// frame
const int FPS = 60;
const int PRE_FRAME_TIME = 1000 / FPS;
Uint32 frameStartTime = 0;
Uint32 frameTime = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadFont(const char* fontPath);
void setRect();
bool timeDisplay();
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


void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

bool loadFont(const char* fontPath)
{
    gFont = TTF_OpenFont(fontPath, 18);
    if(gFont == nullptr)
    {
        printf("TTF Open Font error %s \n", TTF_GetError() );
        return false;
    }
    return true;
}

bool timeDisplay()
{
    std::stringstream sstream;
    sstream << "times: " << loopCount / (SDL_GetTicks() / 1000.f);

    SDL_Surface* tmpSurface = TTF_RenderText_Solid(gFont, sstream.str().c_str(), fontColor);
    if(tmpSurface == nullptr)
    {
        printf("TTF RenderTextSolid Error: \n", TTF_GetError());
        return false;
    }
    fontWidth = tmpSurface->w;
    fontHeight = tmpSurface->h;

    gFontTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    if (gFontTexture == nullptr)
    {
        printf("SDL Create Texture from surface error %s \n", SDL_GetError() );
        return false;
    }

    SDL_FreeSurface(tmpSurface);
    return true;
}

void setRect()
{
    // font 
    dstRectFont.x = 50; dstRectFont.y = 100;
    dstRectFont.h = 18; dstRectFont.w = 100;
}

int main(int argc, char* argv[])
{
    if ( init("example16", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {

        SDL_Event e;
        bool isRunning = true;
        loadFont("ttf/font01.ttf");
        setRect();

        while(isRunning)
        {
            frameStartTime = SDL_GetTicks();
            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
            }

            // 设置背景色
            timeDisplay();
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer, gFontTexture, nullptr, &dstRectFont);
            SDL_RenderPresent(gRenderer);
            loopCount+=1;

            frameTime = SDL_GetTicks() - frameStartTime;
            // 实际一帧花费的时间 < 规定一帧花费的时间
            if (frameTime < PRE_FRAME_TIME)
            {
                SDL_Delay(PRE_FRAME_TIME - frameTime);
            }
        }
    }
    close();
}
