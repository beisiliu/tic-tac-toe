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
#include <iostream>


MainGame::MainGame()
{
    initData();
    gWindow = nullptr;
    gRenderer = nullptr;
}

void MainGame::initData(){
        // init variables
    isGameRunning = true;
    playerLetter = 0;
    computerLetter = 0;

    // init board
    for (int i = 0; i < board.size(); ++i)
    {
        board[i] = 0;
    }
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
    imgPath = setting["path"]["img_path"];
    ttfPath = setting["path"]["ttf_path"];
    if ( sceneFirstTexture.loadFont(ttfPath.c_str(), 18, setting["text"]["FirstScenes"], gRenderer) == false ) return false;
    if ( sceneSecondTexturePlayer.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_play"], gRenderer) == false ) return false;
    if ( sceneSecondTextureComputer.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_computer"], gRenderer) == false ) return false;
    if ( sceneSecondTextureRun.loadFont(ttfPath.c_str(), 12, setting["text"]["SecondScenes_run"], gRenderer) == false ) return false;
    if ( sceneThirdTextureX.loadFont(ttfPath.c_str(), 24, setting["text"]["ThirdScenesY"], gRenderer) == false ) return false;
    if ( sceneThirdTextureY.loadFont(ttfPath.c_str(), 24, setting["text"]["ThirdScenesN"], gRenderer) == false ) return false;
    if ( sceneThirdTexturePlayAgain.loadFont(ttfPath.c_str(), 18, setting["text"]["ThirdScenesPlayAgain"], gRenderer) == false ) return false;

    go = data.whoGoFirst();
    // go = "player";
    std::cout << go << std::endl;
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
        if ( playerLetter == 0 )
        {
            if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 70 and LButton::pLButtonInstance()->getLButtonDownX() < 118 ) and
                 ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
            {
                playerLetter = circle;
                computerLetter = diff;
                LButton::pLButtonInstance()->mPostion.x = 0;
                LButton::pLButtonInstance()->mPostion.y = 0;
                
            }
            if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 160 and LButton::pLButtonInstance()->getLButtonDownY() < 208 ) and
                 ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
            {
                playerLetter = diff;
                computerLetter = circle;
                LButton::pLButtonInstance()->mPostion.x = 0;
                LButton::pLButtonInstance()->mPostion.y = 0;
            }
        }
        else
        {
            LButton::pLButtonInstance()->mPostion.x = LButton::pLButtonInstance()->getLButtonDownX();
            LButton::pLButtonInstance()->mPostion.y = LButton::pLButtonInstance()->getLButtonDownY();
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
    if ( ( !data.isWin(playerLetter, board) ) and ( !data.isWin(computerLetter, board) ) and ( !data.boardFull(board)))
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
        
        if ( playerLetter == circle )
        {
            // reuse scenes01 picture
            sceneFirstTexture.imgClipAndShow(gRenderer, 360, 20, circle);
            sceneFirstTexture.imgClipAndShow(gRenderer, 360, 50, diff);
        }
        else
        {
            // reuse scenes01 picture
            sceneFirstTexture.imgClipAndShow(gRenderer, 360, 20, diff);
            sceneFirstTexture.imgClipAndShow(gRenderer, 360, 50, circle);
        }
        
        sceneSecondTextureRun.fontShow(gRenderer, 300, 100);
        sceneSecondTextureWhoRun.fontShow(gRenderer, 315, 120);
        
        // drawBoard
        drawBoard();
        if ( ( go == "player" ) and ( !data.isWin(computerLetter, board) ))
        {         
            board[data.postionXY(LButton::pLButtonInstance()->mPostion.x, LButton::pLButtonInstance()->mPostion.y)] = playerLetter;
            if ( board[data.postionXY(LButton::pLButtonInstance()->mPostion.x, LButton::pLButtonInstance()->mPostion.y)] == playerLetter 
                 and LButton::pLButtonInstance()->mPostion.x != 0)
            {
                if ( data.isWin(playerLetter, board) )
                {
                    result = "player win";
                    drawBoard();
                    SDL_RenderPresent(gRenderer);
                    SDL_Delay(1000);
                    renderer03();
                }
                if ( data.boardFull(board) )
                {       
                    result = "tied";
                    drawBoard();
                    SDL_RenderPresent(gRenderer);
                    SDL_Delay(1000);
                    renderer03();
                }
                LButton::pLButtonInstance()->mPostion.x = 0;
                LButton::pLButtonInstance()->mPostion.y = 0;
                go = "computer";  
            }

        }
        if ( ( go == "computer") and ( !data.isWin(playerLetter, board) ) )
        {
            board[data.computerRun(board, playerLetter, computerLetter)] = computerLetter;
            if ( data.isWin(computerLetter, board) )
            {
                result = "computer win";
                drawBoard();
                SDL_RenderPresent(gRenderer);
                SDL_Delay(1000);
                renderer03();
            }
            if ( data.boardFull(board) )
            {       
                result = "tied";
                drawBoard();
                SDL_RenderPresent(gRenderer);
                SDL_Delay(1000);
                renderer03();
            }
            go = "player"; 
        }

        SDL_RenderPresent(gRenderer);
    }
    else
    {
        renderer03();
    }

}

void MainGame::renderer03()
{

    // draw playground
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    // who win or tied
    if ( sceneThirdTextureWhoWin.loadFont(ttfPath.c_str(), 18, result, gRenderer) )
    {
        sceneThirdTextureWhoWin.fontShow(gRenderer, 50, 50);
    }

    // font play again
    sceneThirdTexturePlayAgain.fontShow(gRenderer, 30, 70);


    sceneFirstDraw.drawRec(gRenderer, 70, 100, 48, 48);
    sceneFirstDraw.drawRec(gRenderer, 160, 100, 48, 48);

    // Y or N
    sceneThirdTextureX.fontShow(gRenderer, 87, 117);
    sceneThirdTextureY.fontShow(gRenderer, 177, 117);

    if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 70 and LButton::pLButtonInstance()->getLButtonDownX() < 118 ) and
            ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
    {
        LButton::pLButtonInstance()->mPostion.x = 0;
        LButton::pLButtonInstance()->mPostion.y = 0;
        initData();
        // renderer01();
    }
    if ( ( LButton::pLButtonInstance()->getLButtonDownX() > 160 and LButton::pLButtonInstance()->getLButtonDownY() < 208 ) and
            ( LButton::pLButtonInstance()->getLButtonDownY() > 100 and LButton::pLButtonInstance()->getLButtonDownY() < 148 ) )
    {
        isGameRunning = false;
    }

    SDL_RenderPresent(gRenderer);
}


void MainGame::update()
{

}


void MainGame::drawBoard()
{
    for (int i = 1; i < 10; ++i)
    {   
        sceneFirstTexture.imgClipAndShow(gRenderer, setting["initCoordinate"][std::to_string(i)]["x"], setting["initCoordinate"][std::to_string(i)]["y"], board[i]);          
    }
    
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
