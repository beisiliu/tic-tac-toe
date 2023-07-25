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

MainGame* MainGame::p = nullptr;
MainGame* MainGame::pInstance()
{
    if ( p==nullptr )
    {
        p = new MainGame();
        return p;
    }
    return p;
}


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
    
    if ( TTF_Init() == -1 )
    {
        printf( "TTF Init Error : %s \n", TTF_GetError());
        return false;
    }
    
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

    if ( sceneFirstTexture.loadFont("lazy.ttf", 18, "Please choose icon", gRenderer) )
    {
        sceneFirstTexture.fontShow(gRenderer, 60, 60);
        sceneFirstDraw.drawRec(gRenderer, 70, 100, 48, 48);
        sceneFirstDraw.drawRec(gRenderer, 160, 100, 48, 48);
        
        sceneFirstTexture.loadImg("icons.png", gRenderer);
        sceneFirstTexture.imgClipAndShow(gRenderer, 77, 107, 1);
        sceneFirstTexture.imgClipAndShow(gRenderer, 167, 107, 2);
    }
    
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
    sceneSecondTexturePlayer.loadFont("lazy.ttf", 12, "  player: ", gRenderer);
    sceneSecondTexturePlayer.fontShow(gRenderer, 300, 30);
    sceneSecondTextureComputer.loadFont("lazy.ttf", 12, "  computer: ", gRenderer);
    sceneSecondTextureComputer.fontShow(gRenderer, 300, 60);
    
    
    sceneSecondTexturePlayer.loadImg("icons.png", gRenderer);
    if ( playerLetter == 'O' )
    {
        sceneSecondTexturePlayer.imgClipAndShow(gRenderer, 360, 20, 1);
        sceneSecondTexturePlayer.imgClipAndShow(gRenderer, 360, 50, 2);
    }
    else
    {
        sceneSecondTexturePlayer.imgClipAndShow(gRenderer, 360, 20, 2);
        sceneSecondTexturePlayer.imgClipAndShow(gRenderer, 360, 50, 1);
    }
    
    
    SDL_RenderPresent(gRenderer);
}


void MainGame::update()
{

}

MainGame::~MainGame()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
}
