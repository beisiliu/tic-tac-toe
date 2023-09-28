#include <SDL2/SDL.h>
#include <stdio.h>
#include "GTexture.h"
#include "Ball.h"
// #include "CheckCollision.h"

class Game
{
public:
    Game();
    ~Game();
    void gameSetting(int w = 640, int h = 480, Uint32 flag = SDL_WINDOW_SHOWN); //设置私有变量
    bool gameInit();    
    bool imgInit();     //读完所有图片
    void gameEvent(SDL_Event e);
    void gameUpdate();
    void gameRender();
    void free();

    bool isRunning = true;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;

private:
    // 窗口属性
    const char *title = "Game";
    const int x = SDL_WINDOWPOS_CENTERED;
    const int y = SDL_WINDOWPOS_CENTERED;
    int w = 640;
    int h = 480;
    Uint32 flag = SDL_WINDOW_SHOWN;
    
    GTexture* ballTexture = new GTexture();
    // 矩形框
    SDL_Rect rect;
    // 求碰撞体框
    SDL_Rect ballColliderRect;
    Ball* ball = new Ball();

};