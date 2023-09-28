#include "Game.h"

Game::Game()
{
    gWindow = nullptr;
    gRenderer = nullptr;
}

Game::~Game()
{
    free();
}

void Game::free()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    delete ballTexture;
	delete ball;
	// delete staticBallTexture;
	// delete checkCollision;
}

void Game::gameSetting(int w, int h, Uint32 flag)
{
    this->w = w;
    this->h = h;
    this->flag = flag;
}

bool Game::gameInit()
{
    if( SDL_Init( SDL_INIT_EVENTS ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
    else
    {
        //Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( title, x, y, w, h, flag );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			//Create  renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				return false;
			}
			else
			{

				//初始化png图片的loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					return false;
				}
			}
        }
    }
    return true;
}

bool Game::imgInit()
{
    if (!ballTexture->loadImg(gRenderer, "img/ball.bmp"))
    {
        printf("load img error \n");
        return false;
    }
	// if (!staticBallTexture->loadImg(gRenderer, "img/default.bmp"))
	// {
	// 	printf("load static ball img error \n");
	// 	return false;
	// }
	// else
	// {
	// 	staticBallTexture->setStaticDstRect(100, 10);
	// }
	// 矩形框
	rect.h = 100; rect.w = 100;
	rect.x = 100; rect.y = 100;
	// 碰撞体框
	ballColliderRect.w = ballTexture->getImgWidth();
	ballColliderRect.h = ballTexture->getImgHeight();
	//printf("%d, %d", ballColliderRect.w,ballColliderRect.h);
    return true;
}

void Game::gameEvent(SDL_Event e)
{
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
		ball->ballEvent(e);

    }
}

void Game::gameUpdate()
{	
	ball->doMove(ballTexture, w, h, rect, ballColliderRect);
}

void Game::gameRender()
{
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0);
	SDL_RenderDrawRect(gRenderer, &rect);
    ball->ballRendererDstMove(gRenderer, ballTexture);
}
