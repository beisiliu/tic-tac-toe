//Key status

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

SDL_Window* gWindow = nullptr;
// SDL_Texture* gTexture = nullptr;
SDL_Renderer* gRenderer = nullptr;

// font
TTF_Font* gFont = nullptr;
SDL_Color textColor = { 0, 0 , 255 };
SDL_Texture* textTexture = nullptr;
SDL_Rect fontRect;

// imgTexture enum
enum MouseStatus
{
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_NONE,
    KEY_TOTAL
};

// imgTexture
SDL_Texture* imgTexture[KEY_TOTAL];

// SDL_Rect mouseRect[MOUSE_TOTAL];
// SDL_Rect mouseDstRect;
// int mouseStatus = 0;

// img and font
int imgWidth = 0;
int imgHeight = 0;
int fontWidth = 0;
int fontHeight = 0;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Texture* loadImg(const char* imgPath);
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

SDL_Texture* loadImg(const char* imgPath)
{
    // 通过一个临时的tmpSurface读取图片
    // SDL_Surface* tmpSurface = IMG_Load(imgPath);
    SDL_Surface* tmpSurface = IMG_Load(imgPath);
    SDL_Texture* imgTexture;
    if (tmpSurface == nullptr )
    {
        printf("load img error, PATH: %s, Error: %s ", imgPath, IMG_GetError());
        return nullptr;
    }
    imgWidth = tmpSurface->w;
    imgHeight = tmpSurface->h;

    imgTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
    if (imgTexture == nullptr )
    {
        printf("Create Texture From Surface Error: %s ", SDL_GetError());
        return nullptr;       
    }

    // 释放临时的tmpSurface
    SDL_FreeSurface(tmpSurface);
    return imgTexture;
}

bool loadTTF(const char* ttfPath, int fontSize, const char* text)
{
    gFont = TTF_OpenFont(ttfPath, fontSize);
    if (gFont == nullptr)
    {
        printf("TTF Open Font Error : %s \n ", TTF_GetError());
        return false;
    }

    SDL_Surface* tmpSurface = TTF_RenderUTF8_Solid_Wrapped(gFont, text, textColor, 64);
    fontWidth = tmpSurface->w;
    fontHeight = tmpSurface->h;
    textTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);

    SDL_FreeSurface(tmpSurface);
    return true;
}

// void setRect()
// {
// //    fontRect.w = fontWidth; fontRect.h = fontHeight;
// //    fontRect.x = 110; fontRect.y = 110;
//     for (int i = 0; i < MOUSE_TOTAL; i++)
//     {
//         mouseRect[i].h = imgHeight / 4; mouseRect[i].w = imgWidth;
//         mouseRect[i].x = 0;
//     }
//     mouseRect[MOUSE_OUT].y = 0;
//     mouseRect[MOUSE_IN].y = 128;
//     mouseRect[MOUSE_DOWN].y = 256;
//     mouseRect[MOUSE_UP].y = 384;

//     mouseDstRect.h = SCREEN_HEIGHT; mouseDstRect.w = SCREEN_WIDTH;
//     mouseDstRect.x = 0; mouseDstRect.y = 0;
// }

void close()
{
    SDL_DestroyWindow(gWindow);
    // SDL_DestroyTexture(gTexture);
    SDL_DestroyRenderer(gRenderer);

    TTF_CloseFont(gFont);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if ( init("example13", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        // load img
        // if ( !loadImg("img/mouseEvent.png") )
        // {        
        //     printf("Load Image Error : ");
        //     return 1;
        // }
        imgTexture[KEY_UP] = loadImg("img/up.bmp");
        imgTexture[KEY_DOWN] = loadImg("img/down.bmp");
        imgTexture[KEY_LEFT] = loadImg("img/left.bmp");
        imgTexture[KEY_RIGHT] = loadImg("img/right.bmp");
        imgTexture[KEY_NONE] = loadImg("img/default.bmp");
        // load ttf
        if ( !loadTTF("ttf/font01.ttf", 16, "DEFAULT") )
        {
            printf("Load ttf error : ");
            return 2;
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

            const Uint8* currentKeyStatus = SDL_GetKeyboardState(nullptr);
            int currentImg = KEY_NONE;
            if( currentKeyStatus[SDL_SCANCODE_UP] )
            {
                currentImg = KEY_UP;
            }
            else if( currentKeyStatus[SDL_SCANCODE_DOWN] )
            {
                currentImg = KEY_DOWN;
            }
            else if( currentKeyStatus[SDL_SCANCODE_LEFT] )
            {
                currentImg = KEY_LEFT;
            }
            else if( currentKeyStatus[SDL_SCANCODE_RIGHT] )
            {
                currentImg = KEY_RIGHT;
            }
            else
            {
                currentImg = KEY_NONE;
            }


            cout << *currentKeyStatus << endl;
            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer, imgTexture[currentImg], nullptr, nullptr);
            // SDL_RenderCopy(gRenderer, textTexture, nullptr, &fontRect);
            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
