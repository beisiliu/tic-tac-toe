//
//  rendererDraw.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/20.
//

#include "rendererDraw.hpp"
void RendererDraw::drawLine(SDL_Renderer* gRenderer, int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void RendererDraw::drawRec(SDL_Renderer *gRenderer, int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect rec;
    rec.x = x1; rec.y = y1; rec.w = x2; rec.h = y2;
    SDL_RenderDrawRect(gRenderer, &rec);
}
