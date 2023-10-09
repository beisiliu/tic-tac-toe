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
	delete bgTexture;
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
	if (!bgTexture->loadImg(gRenderer, "img/bg.png"))
	{
		printf("load img error \n");
		return false;
	}
	// 初始化cameraRect
	cameraDstRect = {0, 0, w, h};
	bgSrcRect = {150, 150, w, h};
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
	ball->doMove(ballTexture, w, h, bgSrcRect.x, bgSrcRect.y);
}

void Game::gameRender()
{
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 0);
	//cameraDstRect的x，y永远是（0,0）h，w 永远是window的w和h
	//bgSrcRect的x，y是变的，h，w永远是window的w和h
	printf("%d\n", bgSrcRect.x);
	SDL_RenderCopy(gRenderer, bgTexture->gTexture, &bgSrcRect, &cameraDstRect);
    ball->ballRendererDstMove(gRenderer, ballTexture);
}
