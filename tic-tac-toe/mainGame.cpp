//
//  mainGame.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/20.
//

#include "mainGame.hpp"
#include "rendererDraw.hpp"
#include "mouseEvent.hpp"
#include "data.hpp"
#include <fstream>


MainGame::MainGame()
{
    // init variables
    isGameRunning = true;
    playerLetter = '1';
    computerLetter = '1';
    
    gWindow = nullptr;
    gRenderer = nullptr;
}

bool MainGame::gameInit(const char *title, int x, int y, int w, int h, Uint32 flags){
    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
    {
        printf( "SDL Init Error : %s \n", SDL_GetError() );
        return false;
    }
    
    gWindow = SDL_CreateWindow(title, x, y, w, h, flags);
    if ( gWindow == nullptr )
    {
        printf( "SDL Create Window Error : %s \n", SDL_GetError() );
        return false;
    }
    
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if ( gRenderer == nullptr )
    {
        printf( "SDL Create Renderer Error : %s \n", SDL_GetError() );
        return false;
    }
    
    std::fstream settingJson("json/setting.json");
    if ( !settingJson )
    {
        printf( "load setting.json error \n" );
        return false;
    }

    if ( TTF_Init() == -1 )
    {
        printf( "TTF Init Error : %s \n", TTF_GetError());
        return false;
    }
  
    setting = json::parse(settingJson);
    std::string imgPath = setting["path"]["img_path"];
    std::string ttfPath = setting["path"]["ttf_path"];
    if ( sceneFirstTexture.loadFont(ttfPath.c_str(), 18, setting["text"]["FirstScenes"], gRenderer) == false ) return false;
    if ( sceneSecondTexturePlayer.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_play"], gRenderer) == false ) return false;
    if ( sceneSecondTextureComputer.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_computer"], gRenderer) == false ) return false;
    if ( sceneSecondTextureRun.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_run"], gRenderer) == false ) return false;
    go = whoGoFirst();
    if ( sceneSecondTextureWhoRun.loadFont(ttfPath.c_str(), 12, go, gRenderer) == false ) return false;
    
    if ( sceneFirstTexture.loadImg(imgPath.c_str(), gRenderer) == false ) return false;
    
    WINDOW_HEIGHT = h;
    WINDOW_WIDTH = w;
    return true;
}

void MainGame::handleEvent()
{
    while ( SDL_PollEvent( &e) )
    {
        if ( e.type == SDL_QUIT )
        {
            isGameRunning = false;
        }
        
        LButton::pLButtonInstance()->handleEvent( e );
        if ( playerLetter == '1' )
        {
            if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 70 and LButton::pLButtonInstance()->getLButtonDownX() < 118 ) and
                 ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
            {
                playerLetter = 'O';
                computerLetter = 'X';
                
            }
            if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 160 and LButton::pLButtonInstance()->getLButtonDownY() < 208 ) and
                 ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
            {
                playerLetter = 'X';
                computerLetter = 'O';
            }
        }

    }
}

// scene01
void MainGame::renderer01()
{
    // backgroud color
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    sceneFirstTexture.fontShow(gRenderer, 60, 60);
    sceneFirstDraw.drawRec(gRenderer, 70, 100, 48, 48);
    sceneFirstDraw.drawRec(gRenderer, 160, 100, 48, 48);

    sceneFirstTexture.imgClipAndShow(gRenderer, 77, 107, 1);
    sceneFirstTexture.imgClipAndShow(gRenderer, 167, 107, 2);

    
    SDL_RenderPresent(gRenderer);

}

// scenes02
void MainGame::renderer02()
{
    // draw playgroud
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);
    
    sceneSecondDraw.drawLine(gRenderer, 0, WINDOW_HEIGHT / 3, WINDOW_WIDTH - 100, WINDOW_HEIGHT / 3);
    sceneSecondDraw.drawLine(gRenderer, 0, WINDOW_HEIGHT / 3 * 2 , WINDOW_WIDTH - 100, WINDOW_HEIGHT / 3 * 2);
    sceneSecondDraw.drawLine(gRenderer, (WINDOW_WIDTH - 100) / 3, 0, (WINDOW_WIDTH - 100) / 3, WINDOW_HEIGHT);
    sceneSecondDraw.drawLine(gRenderer, (WINDOW_WIDTH - 100) / 3 * 2 , 0, (WINDOW_WIDTH - 100) / 3 * 2 , WINDOW_HEIGHT);
    
    // player and computer choose
    sceneSecondTexturePlayer.fontShow(gRenderer, 300, 30);
    sceneSecondTextureComputer.fontShow(gRenderer, 300, 60);
    
    
//    sceneSecondTexturePlayer.loadImg("icons.png", gRenderer);
    if ( playerLetter == 'O' )
    {
        sceneFirstTexture.imgClipAndShow(gRenderer, 360, 20, 1);
        sceneFirstTexture.imgClipAndShow(gRenderer, 360, 50, 2);
    }
    else
    {
        sceneFirstTexture.imgClipAndShow(gRenderer, 360, 20, 2);
        sceneFirstTexture.imgClipAndShow(gRenderer, 360, 50, 1);
    }
    
    sceneSecondTextureRun.fontShow(gRenderer, 300, 100);
    sceneSecondTextureWhoRun.fontShow(gRenderer, 315, 120);
    
    if ( go == "player")
    {
        
    }
    
    
    SDL_RenderPresent(gRenderer);
}


void MainGame::update()
{

}

void MainGame::close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
}

MainGame::~MainGame()
{
    close();
}
