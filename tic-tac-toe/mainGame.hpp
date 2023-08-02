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
#include "include/nlohmann/json.hpp"
#include "data.hpp"
#include <array>

using json = nlohmann::json;

class MainGame
{
public:
    
    bool isGameRunning;
    int playerLetter;
    int computerLetter;
    std::string go;
    json setting;
    std::array<int, 10> board;
    
    void initData();
    bool gameInit(const char *title, int x, int y, int w, int h, Uint32 flags);
    void handleEvent();
    void renderer01();
    void renderer02();
    void renderer03();
    void update();
    void close();
    
    void drawBoard();
    MainGame();
    ~MainGame();

private:
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;

    std::string imgPath;
    std::string ttfPath;
    std::string result;
    
    const int circle = 1;
    const int diff = 2;
    
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

    LoadTexture sceneThirdTextureY;
    LoadTexture sceneThirdTextureX;
    LoadTexture sceneThirdTexturePlayAgain;
    LoadTexture sceneThirdTextureWhoWin;

    Data data;
};

#endif /* mainGame_hpp */
