//
//  loadTexture.hpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/21.
//

#ifndef loadTexture_hpp
#define loadTexture_hpp

#include <stdio.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
class LoadTexture
{
public:
    LoadTexture();
    ~LoadTexture();
    bool loadImg(const char *file, SDL_Renderer *renderer);
    bool loadFont(const char *fileTTF, int fontSize, std::string str, SDL_Renderer* gRenderer);
    void imgClipAndShow(SDL_Renderer* gRenderer, int positionX, int positionY, int flag);
    void fontShow(SDL_Renderer* gRenderer, int positionX, int positionY);
    void free();
    
private:
    SDL_Texture* gTexture;
    TTF_Font* gFont;
    SDL_Color fontRed = { 255, 0, 0 };
    
    int imgWidth;
    int imgHeight;
    
    int fontWidth;
    int fontHeight;

};

#endif /* loadTexture_hpp */
