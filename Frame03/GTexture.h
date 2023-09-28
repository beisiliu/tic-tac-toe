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
    // dst move pic
    void textureRenderDstMove(SDL_Renderer* gRenderer, int postionX, int postionY);
    // static pic
    void setStaticDstRect(const int staticX, const int staticY);
    SDL_Rect getDstRect();
    void textureRenderDstStatic(SDL_Renderer* gRenderer);

    // get IMG w and h
    int getImgWidth();
    int getImgHeight();

private:
    SDL_Texture *gTexture;
    int imgWidth;
    int imgHeight;

    SDL_Rect dstRect;

};
