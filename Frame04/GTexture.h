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
    void textureRenderDstMove(SDL_Renderer* gRenderer, int postionX, int postionY, SDL_Rect *srcRect = nullptr);
    // static pic
    void setStaticDstRect(const int staticX, const int staticY);
    void textureRenderDstStatic(SDL_Renderer* gRenderer);

    SDL_Rect getDstRect();

    // get IMG w and h
    int getImgWidth();
    int getImgHeight();
    
    SDL_Texture *gTexture;
private:

    int imgWidth;
    int imgHeight;

    SDL_Rect dstRect;

};
