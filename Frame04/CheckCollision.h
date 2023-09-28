#include <SDL2/SDL.h>
#pragma once
class CheckCollision
{
public:
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    // int checkCollisionNum(SDL_Rect a, SDL_Rect b); // 1: up, 2: down, 3: left, 4: right, 5: None collision

};