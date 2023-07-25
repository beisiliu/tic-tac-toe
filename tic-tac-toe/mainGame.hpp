//
//  mainGame.hpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/20.
//

#ifndef mainGame_hpp
#define mainGame_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "rendererDraw.hpp"
#include "loadTexture.hpp"
#include <SDL2_ttf/SDL_ttf.h>
#include <string>


class MainGame
{
public:
//    static MainGame* p;
//    static MainGame* pInstance();
    
    bool isGameRunning;
    char playerLetter;
    char computerLetter;
    std::string go;
    
    bool gameInit(const char *title, int x, int y, int w, int h, Uint32 flags);
    void handleEvent();
    void renderer01();
    void renderer02();
    void update();
    void close();
    
    int getWindowWIDTH();
    int getWindowHEIGHT();
    
    MainGame();
    ~MainGame();

private:
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    
    
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event e;
    
    RendererDraw sceneFirstDraw;
    LoadTexture sceneFirstTexture;
    
    RendererDraw sceneSecondDraw;
    LoadTexture sceneSecondTexturePlayer;
    LoadTexture sceneSecondTextureComputer;
    LoadTexture sceneSecondTextureRun;
    LoadTexture sceneSecondTextureWhoRun;
};

#endif /* mainGame_hpp */
