// 后面要做成框架

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = nullptr;
SDL_Texture* gTexture = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Rect roadRect;
SDL_Rect personStandSrcRect;
SDL_Rect personRect[6];

int imgWidth = 0;
int imgHeight = 0;
// 控制人物移动
int idleX = 0;
int srcX = 0;
int dstX = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
bool loadImg(const char* imgPath);
void setRect();
void close();

// SDL_Rect personRect[6]中的值
enum PERSON_STATUS
{
    PERSON_IDLE_SRC,
    PERSON_IDLE_DST,
    PERSON_LEFT_SRC,
    PERSON_LEFT_DST,
    PERSON_RIGHT_SRC,
    PERSON_RIGHT_DST
};

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

void setRect()
{
    // road
    roadRect.x = 0; roadRect.y = SCREEN_WIDTH / 5 * 4;
    roadRect.w = SCREEN_WIDTH; roadRect.h = SCREEN_WIDTH / 5;

    // idle
    personRect[PERSON_IDLE_SRC].x = idleX; personRect[PERSON_IDLE_SRC].y = 0;
    personRect[PERSON_IDLE_SRC].w = imgWidth / 4; personRect[PERSON_IDLE_SRC].h = imgHeight / 2;
    personRect[PERSON_IDLE_DST].x = dstX; personRect[PERSON_IDLE_DST].y = (SCREEN_WIDTH / 5 * 4) - imgHeight;
    personRect[PERSON_IDLE_DST].w = imgWidth / 2;personRect[PERSON_IDLE_DST].h = imgHeight;

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
        if ( !loadImg("img/animation.png") )
        {        
            printf("Load Image Error : ");
            return 1;
        }
        // setRect();
        SDL_Event e;
        bool isRunning = true;
        while(isRunning)
        {
            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);

            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                if(e.type == SDL_KEYDOWN)
                {
                    if(e.key.keysym.sym == SDLK_LEFT)
                    {

                    }
                    if(e.key.keysym.sym == SDLK_RIGHT)
                    {

                    }
                }                
            }
            for (idleX = 0; idleX < 64; idleX += 16)
            {
                setRect();
                SDL_RenderCopy(gRenderer, gTexture, &personRect[PERSON_IDLE_SRC], &personRect[PERSON_IDLE_DST]);

                // 设置road
                SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
                SDL_RenderFillRect(gRenderer, &roadRect);
                SDL_RenderPresent(gRenderer);

                if (idleX == 64)
                {
                    idleX = 0;
                }
            }

            // SDL_RenderCopy(gRenderer, gTexture, &personRect[PERSON_IDLE_SRC], &personRect[PERSON_IDLE_DST]);
            // // 设置road
            // SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
            // SDL_RenderFillRect(gRenderer, &roadRect);
            // SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
