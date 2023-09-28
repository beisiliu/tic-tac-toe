#include "Ball.h"

Ball::Ball()
{
    postionX = 0, postionY = 0;
    speedX = 0, speedY = 0;

    // ballColliderRect.w = ballTexture->getImgWidth();
    // ballColliderRect.h = ballTexture->getImgHeight();
    printf("ball");
}

Ball::~Ball()
{

}

void Ball::free()
{
    delete checkCollision;
}

void Ball::ballSetting(int speed)
{
    this->speed = speed;
}

void Ball::ballEvent(SDL_Event e)
{
    ballSetting(speed = 10);
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
            case SDLK_RIGHT: speedX -= speed; break;
            case SDLK_LEFT:  speedX += speed; break;
            case SDLK_UP:    speedY += speed; break;
            case SDLK_DOWN:  speedY -= speed; break;
        }
    }
}


void Ball::doMove(GTexture* ballTexture, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Rect rect, SDL_Rect ballColliderRect)
{
    postionX += speedX;
    ballColliderRect.x = postionX;
    postionY += speedY;
    ballColliderRect.y = postionY;

    printf("c, %d, %d \n", ballColliderRect.x, ballColliderRect.y);
    // 左右边界判断
    if( (ballTexture->getImgWidth() + postionX > SCREEN_WIDTH) or (postionX < 0) or (checkCollision->checkCollision(ballColliderRect, rect)))
    {
        postionX -= speedX;
        ballColliderRect.x = postionX;
        printf(" a, (%d, %d)\n", ballColliderRect.x, ballColliderRect.y);
    }
    // ballColliderRect的值，每次调用，都是从外面传递进来的，写在后面ballColliderRect.y在调用第一个if的时候，判断总是为0，所以要写在最前面。
    // postionY += speedY;
    // ballColliderRect.y = postionY;
    printf("d, %d, %d \n", ballColliderRect.x, ballColliderRect.y);
    // 上下边界判断
    if( (ballTexture->getImgHeight() + postionY > SCREEN_HEIGHT) or (postionY < 0) or (checkCollision->checkCollision(ballColliderRect, rect)))
    {
        postionY -= speedY;
        ballColliderRect.y = postionY;
        printf(" b, (%d, %d)\n", ballColliderRect.x, ballColliderRect.y);
    }
}

void Ball::ballRendererDstMove(SDL_Renderer* gRenderer, GTexture* ballTexture)
{
    ballTexture->textureRenderDstMove(gRenderer, postionX, postionY);
}