// ball move

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <stdio.h>


const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

// img
SDL_Texture* ballTexture = nullptr;

// ball move
int ballX = 0;
int ballY = 0;
int moveSpeed = 71;
SDL_Rect ballRect;

// frame
const int FPS = 120;
const int PRE_FRAME_TIME = 1000 / FPS;
Uint32 frameStartTime = 0;
Uint32 frameTime = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Texture*  loadImg(const char* imgPath);
void ballMove(SDL_Event e);
void setBallRect();
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

SDL_Texture* loadImg(const char* imgPath)
{
    SDL_Texture* imgTexture = IMG_LoadTexture(gRenderer, imgPath);
    if (imgTexture == nullptr)
    {
        printf("load img texture error %s \n", IMG_GetError());
        return nullptr;
    }
    return imgTexture;
}

void ballMove(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN )
    {
        if(e.key.keysym.sym == SDLK_RIGHT)
        {
            if (ballX < (SCREEN_WIDTH - 16))
            {
                ballX += moveSpeed;
            }
        }
        if(e.key.keysym.sym == SDLK_LEFT)
        {
            if (ballX > 0)
            {
                ballX -= moveSpeed;
            }
        }
        if(e.key.keysym.sym == SDLK_UP)
        {
            if (ballY > 0)
            {
                ballY -= moveSpeed;
            }
        }
        if(e.key.keysym.sym == SDLK_DOWN)
        {
            if (ballY < (SCREEN_HEIGHT - 16) )
            {
                ballY += moveSpeed;
            }
        }
        
    }
}

void setBallRect()
{
    ballRect.x = ballX; ballRect.y = ballY;
    ballRect.h = 16; ballRect.w = 16;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}


int main(int argc, char* argv[])
{
    if ( init("example17", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        // load img
        ballTexture = loadImg("img/ball.bmp");

        SDL_Event e;
        bool isRunning = true;
        while(isRunning)
        {
            frameStartTime = SDL_GetTicks();
            while(SDL_PollEvent(&e))
            {
                if(e.type == SDL_QUIT)
                {
                    isRunning = false;
                }
                ballMove(e);
            }

            // 设置背景色

            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            setBallRect();
            SDL_RenderCopy(gRenderer, ballTexture, nullptr, &ballRect);
            SDL_RenderPresent(gRenderer);

            // frame
            frameTime = SDL_GetTicks() - frameStartTime;
            if (frameTime < PRE_FRAME_TIME)
            {
                SDL_Delay(PRE_FRAME_TIME - frameTime);
            }
        }
    }
    close();
}
