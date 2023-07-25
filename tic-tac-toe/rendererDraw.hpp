//
//  rendererDraw.hpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/20.
//

#ifndef rendererDraw_hpp
#define rendererDraw_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
class RendererDraw
{
public:
    void drawLine(SDL_Renderer* gRenderer, int x1, int y1, int x2, int y2);
    void drawRec(SDL_Renderer* gRenderer, int x1, int y1, int x2, int y2);
    
};

#endif /* rendererDraw_hpp */
