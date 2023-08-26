//font

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = nullptr;
SDL_Texture* gTexture = nullptr;
SDL_Renderer* gRenderer = nullptr;

TTF_Font* gFont = nullptr;
SDL_Color textColor = { 0, 0 , 255 };
SDL_Texture* textTexture = nullptr;

SDL_Rect fontRect;

int imgWidth = 0;
int imgHeight = 0;
int fontWidth = 0;
int fontHeight = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadImg(const char* imgPath);
bool loadTTF(const char* ttfPath, int fontSize, const char* text);
void setRect();
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

bool loadImg(const char* imgPath)
{
    // 通过一个临时的tmpSurface读取图片
    // SDL_Surface* tmpSurface = IMG_Load(imgPath);
    SDL_Surface* tmpSurface = IMG_Load(imgPath);
    if (tmpSurface == nullptr )
    {
        printf("load img error, PATH: %s, Error: %s ", imgPath, IMG_GetError());
        return false;
    }
    imgWidth = tmpSurface->w;
    imgHeight = tmpSurface->h;

    gTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    if (gTexture == nullptr )
    {
        printf("Create Texture From Surface Error: %s ", SDL_GetError());
        return false;       
    }

    // 释放临时的tmpSurface
    SDL_FreeSurface(tmpSurface);
    return true;
}

bool loadTTF(const char* ttfPath, int fontSize, const char* text)
{
    gFont = TTF_OpenFont(ttfPath, fontSize);
    if (gFont == nullptr)
    {
        printf("TTF Open Font Error : %s \n ", TTF_GetError());
        return false;
    }

    // gFont 都读到了，一般不会nullptr，当然加个if判断也可以
    // SDL_Surface* tmpSurface = TTF_RenderText_Solid(gFont, text, textColor);
    // SDL_Surface* tmpSurface = TTF_RenderUTF8_Solid(gFont, text, textColor);
    SDL_Surface* tmpSurface = TTF_RenderUTF8_Solid_Wrapped(gFont, text, textColor, 64);
    fontWidth = tmpSurface->w;
    fontHeight = tmpSurface->h;
    printf("%d \n", fontWidth);
    printf("%d \n", fontHeight);
    textTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return true;
}

void setRect()
{
   fontRect.w = fontWidth; fontRect.h = fontHeight;
    fontRect.x = 110; fontRect.y = 110;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyTexture(gTexture);
    SDL_DestroyRenderer(gRenderer);

    TTF_CloseFont(gFont);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example011", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        // load img
        if ( !loadImg("img/helloWorld.png") )
        {        
            printf("Load Image Error : ");
            return 1;
        }
        // load ttf
        if ( !loadTTF("ttf/font01.ttf", 16, "啊啊啊啊啊啊啊啊") )
        {
            printf("Load ttf error : ");
            return 2;
        }
        setRect();
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

            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);

            SDL_RenderCopy(gRenderer, textTexture, nullptr, &fontRect);
            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
