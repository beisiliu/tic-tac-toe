#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = nullptr;
SDL_Texture* gTexture = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Point center;

int imgWidth = 0;
int imgHeight = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadImg(const char* imgPath);
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
    SDL_DestroyTexture(gTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example010", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        if ( !loadImg("img/helloWorld.png") )
        {        
            printf("Load Image Error : ");
            return 1;
        }
        // setRect();
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

            // for (int i = 0; i < 3; i++)
            // {
            //     SDL_RenderCopy(gRenderer, gTexture, &srcRect[i], &srcRect[i]);
            // }
            center.x = 0; center.y = 0;
            SDL_RenderCopyEx(gRenderer, gTexture, nullptr, nullptr, 45, &center, SDL_FLIP_NONE);
            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
