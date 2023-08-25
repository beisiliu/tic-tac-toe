// load image

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = nullptr;
SDL_Surface* gSurface = nullptr;
SDL_Texture* gTexture = nullptr;
SDL_Renderer* gRenderer = nullptr;
int imgWidth = 0;
int imgHeight = 0;
//SDL_Surface* gHelloWorld300 = nullptr;

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

    // gSurface = SDL_GetWindowSurface( gWindow );
    // if ( gSurface == nullptr )
    // {
    //     printf("SDL GetWindowSurface Error: %s \n", SDL_GetError());
    //     return false;
    // }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if ( gRenderer == nullptr )
    {
        printf("SDL CreateRenderer Error: %s \n", SDL_GetError());
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
        printf("load img error, PATH: %s, Error: %s ", imgPath, SDL_GetError());
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

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example06", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        if ( !loadImg("img/helloWorld.png") )
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
            SDL_Rect destRect;
            destRect.x = 100;
            destRect.y = 100;
            destRect.h = SCREEN_HEIGHT/2;
            destRect.w = SCREEN_WIDTH/2;

            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            // SDL_RenderCopy(gRenderer, gTexture, nullptr, &destRect);

            // 填充色矩形
            SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
            SDL_RenderFillRect( gRenderer, &destRect );

            // 无填充色矩形
            SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
            SDL_RenderDrawRect( gRenderer, &destRect );

            // 划线
            SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
            SDL_RenderDrawLine( gRenderer, 100, 100, 200, 200);

            // 画点
            SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
            for(int x = 100; x < 300; x += 5)
            {
                SDL_RenderDrawPoint(gRenderer, x, 100);
            }

            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
