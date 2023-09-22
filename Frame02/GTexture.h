#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#pragma once

class GTexture
{
public:
    GTexture();
    ~GTexture();
    void free();

    bool loadImg(SDL_Renderer* gRenderer, const char* imgPath);
    void textureRenderDstMove(SDL_Renderer* gRenderer, int postionX, int postionY);
    int getImgWidth();
    int getImgHeight();

private:
    SDL_Texture *gTexture;
    int imgWidth;
    int imgHeight;

    SDL_Rect dstRect;

};
