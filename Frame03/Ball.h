#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include "GTexture.h"
#include "CheckCollision.h"
// #include "Game.h"

#pragma once

class Ball
{
public:
    Ball();
    ~Ball();
    void ballSetting(int speed = 10);
    void ballEvent(SDL_Event e);
    void doMove(GTexture* ballTexture, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Rect rect, SDL_Rect ballColliderRect);
    void ballRendererDstMove(SDL_Renderer* gRenderer, GTexture* ballTexture);
    void free();

private:
    int postionX, postionY;
    int speedX, speedY;
    int speed = 10;

    // SDL_Rect ballColliderRect;
    CheckCollision* checkCollision = new CheckCollision();
};