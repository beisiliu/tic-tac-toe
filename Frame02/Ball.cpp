#include "Ball.h"

Ball::Ball()
{
    postionX = 0, postionY = 0;
    speedX = 0, speedY = 0;
}

Ball::~Ball()
{

}

void Ball::free()
{

}

void Ball::ballSetting(int speed)
{
    this->speed = speed;
}

void Ball::ballEvent(SDL_Event e)
{
    ballSetting(speed = 5);
    if(e.type == SDL_KEYDOWN and e.key.repeat == 0)
    {
        switch (e.key.keysym.sym )
        {
            case SDLK_RIGHT: speedX += speed; break;
            case SDLK_LEFT:  speedX -= speed; break;
            case SDLK_UP:    speedY -= speed; break;
            case SDLK_DOWN:  speedY += speed; break;
        }
    }
    
    if(e.type == SDL_KEYUP and e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
            case SDLK_RIGHT: speedX -=speed; break;
            case SDLK_LEFT:  speedX += speed; break;
            case SDLK_UP:    speedY += speed; break;
            case SDLK_DOWN:  speedY -= speed; break;
        }
    }
}

void Ball::doMove(GTexture* ballTexture, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    postionX += speedX;
    if(ballTexture->getImgWidth() + postionX > SCREEN_WIDTH or postionX < 0)
    {
        postionX -= speedX;
    }
    printf("%d", speedX);
    postionY += speedY;
    if(ballTexture->getImgHeight() + postionY > SCREEN_HEIGHT or postionY < 0)
    {
        postionY -= speedY;
    }
}

void Ball::ballRendererDstMove(SDL_Renderer* gRenderer, GTexture* ballTexture)
{
    ballTexture->textureRenderDstMove(gRenderer, postionX, postionY);
}