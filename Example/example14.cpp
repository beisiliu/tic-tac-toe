// audio

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
int imgWidth = 0;
int imgHeight = 0;

// audio
Mix_Music* gMusic = nullptr;
Mix_Chunk* gM2 = nullptr;

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Texture* loadImg(const char* imgPath);
bool loadAudio();
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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        printf("Mix Open Audio Error %s \n", Mix_GetError());
        return false;
    }
    return true;

}

SDL_Texture* loadImg(const char* imgPath)
{
    // 通过一个临时的tmpSurface读取图片
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

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

bool loadAudio()
{
    gMusic = Mix_LoadMUS("audio/M1.mp3");
    if (gMusic == nullptr)
    {
        printf("load music error %s \n", Mix_GetError());
        return false;
    }
    gM2 = Mix_LoadWAV("audio/M2.Wav");
    if (gM2 == nullptr)
    {
        printf("load WAV error %s \n", Mix_GetError());
        return false;
    }
    return true;
}


int main(int argc, char* argv[])
{
    if ( init("example14", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN) )
    {
        if ( !loadAudio() )
        {
            printf("load Audio error \n");
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
                if(e.type == SDL_KEYDOWN)
                {
                    if(e.key.keysym.sym == SDLK_1)
                    {
                        Mix_PlayChannel(-1, gM2, 0);
                    }
                    if(e.key.keysym.sym == SDLK_SPACE)
                    {
                        if( Mix_PausedMusic() == 1)
                        {
                            Mix_ResumeMusic();
                        }
                        else
                        {
                            Mix_PauseMusic();
                        }

                    }
                    if(e.key.keysym.sym == SDLK_s)
                    {
                        Mix_HaltMusic();
                    }
                    if(e.key.keysym.sym == SDLK_b)
                    {
                        if ( Mix_PlayingMusic() == 0)
                        {
                            Mix_PlayMusic(gMusic, -1);
                        }
                    }
                }               
            }

            // Mix_PlayMusic(gMusic, -1);
            // 设置背景色
            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
            SDL_RenderClear(gRenderer);
            // SDL_RenderCopy(gRenderer, imgTexture[currentImg], nullptr, nullptr);
            // SDL_RenderCopy(gRenderer, textTexture, nullptr, &fontRect);
            SDL_RenderPresent(gRenderer);
        }
    }
    close();
}
