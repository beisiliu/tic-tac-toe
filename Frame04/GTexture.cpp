#include "GTexture.h"

GTexture::GTexture()
{
    gTexture = nullptr;
    imgWidth = 0;
    imgHeight = 0;
}

GTexture::~GTexture()
{
    free();
}

void GTexture::free()
{
    if(gTexture != nullptr)
    {
        gTexture = nullptr;
        imgWidth = 0;
        imgHeight = 0;
    }
}

bool GTexture::loadImg(SDL_Renderer* gRenderer, const char* imgPath)
{
    SDL_Surface* tmpSurface = IMG_Load(imgPath);
    if (tmpSurface == nullptr)
    {
        printf("load img : %s error : %s \n", imgPath, IMG_GetError());
        return false;
    }
    else
    {
        gTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
        if (gTexture == nullptr)
        {
            printf("create texture from surface error : %s \n", SDL_GetError());
            return false;
        }
        else
        {
            imgWidth = tmpSurface->w;
            imgHeight = tmpSurface->h;
            dstRect.w = imgWidth;
            dstRect.h = imgHeight;
            SDL_FreeSurface(tmpSurface);
            return true;
        }

    }
    return true;
}

void GTexture::textureRenderDstMove(SDL_Renderer* gRenderer, int postionX, int postionY, SDL_Rect* srcRect)
{
    dstRect.x = postionX; dstRect.y = postionY;
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &dstRect);

}

SDL_Rect GTexture::getDstRect()
{
    return dstRect;
}

void GTexture::setStaticDstRect(const int staticX, const int staticY)
{
    dstRect.x = staticX;
    dstRect.y = staticY;
}

void GTexture::textureRenderDstStatic(SDL_Renderer* gRenderer)
{
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &dstRect);
}


int GTexture::getImgHeight()
{
    return imgHeight;
}

int GTexture::getImgWidth()
{
    return imgWidth;
}