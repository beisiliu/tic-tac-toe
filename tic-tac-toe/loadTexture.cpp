//
//  loadTexture.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/21.
//

#include "loadTexture.hpp"
#include "mainGame.hpp"

LoadTexture::LoadTexture()
{
    gTexture = nullptr;
    imgWidth = 0;
    imgHeight = 0;
}

LoadTexture::~LoadTexture()
{
    free();
}

bool LoadTexture::loadImg(const char *file, SDL_Renderer *renderer)
{
    SDL_Surface* surfLoadImg = IMG_Load(file);
    if ( surfLoadImg == nullptr )
    {
        printf("load Img error : %s \n", SDL_GetError());
        return false;
    }
    
    gTexture = SDL_CreateTextureFromSurface(renderer, surfLoadImg);
    if ( gTexture == nullptr )
    {
        printf("create Texture error : %s \n", SDL_GetError());
        return false;
    }
    
    imgWidth = surfLoadImg->w;
    imgHeight = surfLoadImg->h;
    
    SDL_FreeSurface(surfLoadImg);
    return true;
    
}

bool LoadTexture::loadFont(const char *fileTTF, int fontSize, std::string str, SDL_Renderer* gRenderer)
{
    gFont = TTF_OpenFont(fileTTF, fontSize);
    if ( gFont == nullptr )
    {
        printf("TTF Open Font Error : %s \n", TTF_GetError());
        return false;
    }
    SDL_Surface* tmpSurface = TTF_RenderText_Solid(gFont, str.c_str(), fontRed );
    if (tmpSurface == nullptr )
    {
        printf("TTF RenderText Solid Error : %s \n", SDL_GetError());
        return false;
    }
    fontWidth = tmpSurface->w;
    fontHeight = tmpSurface->h;
    
    gTexture = SDL_CreateTextureFromSurface( gRenderer, tmpSurface );
    SDL_FreeSurface(tmpSurface);
    
    return true;
}

// x and y is IMG in the surface position , not usual, must confirm the img;
void LoadTexture::imgClipAndShow(SDL_Renderer* gRenderer, int positionX, int positionY, int flag)
{
    SDL_Rect s1;
    SDL_Rect s2;
    
    s1.x = 0;
    s1.y = 0;
    s1.w = imgWidth / 2;
    s1.h = imgHeight;
    
    s2 = s1;
    // circle or text is 1, cha is 2
    if ( flag == 1 ) { s2.x = positionX; s2.y = positionY;}
    if ( flag == 2 ) { s1.x = imgWidth / 2; s2.x = positionX; s2.y = positionY;}

    SDL_RenderCopyEx(gRenderer, gTexture, &s1, &s2, 0, nullptr, SDL_FLIP_NONE);
}

void LoadTexture::fontShow(SDL_Renderer *gRenderer, int positionX, int positionY)
{
    SDL_Rect s1;
    SDL_Rect s2;
    
    s1.x = 0;
    s1.y = 0;
    s1.w = fontWidth;
    s1.h = fontHeight;
    
    s2 = s1;
    s2.x = positionX; s2.y = positionY;


    SDL_RenderCopy(gRenderer, gTexture, &s1, &s2);
}


void LoadTexture::free()
{
    if ( gTexture != nullptr )
    {
        SDL_DestroyTexture(gTexture);
        gTexture = nullptr;
        imgWidth = 0;
        imgHeight = 0;
    }
}
