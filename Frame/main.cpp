#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include "GTexture.h"
#include "Ball.h"

//global var
SDL_Window* gWindow;
SDL_Renderer* gRenderer;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
// GTexture *ballTexture = new GTexture();
// Ball *ball = new Ball();
GTexture ballTexture;
Ball ball;

bool init();
bool loadMedia();
void quit();

bool init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
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

bool loadMedia()
{
    if ( !ballTexture.loadFromFile("img/ball.bmp", gRenderer) )
    {
        printf("load ball.bmp error \n");
        return false;
    }

    return true;
}

void quit()
{
    //Free loaded images
	ballTexture.free();

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}

int main(int argc, char* args[])
{
    if (!init())
    {
        printf("init Error \n");
        return 1;
    }
    if (!loadMedia())
    {
        printf("load media error \n");
        return 2;
    }
    SDL_Event e;
    bool isRunning = true;
    while(isRunning)
    {
		while( SDL_PollEvent(&e) )
		{
			if(e.type == SDL_QUIT)
			{
				isRunning = false;
			}
			ball.handleEvent(e);
			// ball.move(SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		ball.move(SCREEN_WIDTH, SCREEN_HEIGHT);
		
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

		SDL_RenderClear(gRenderer);
		ball.render(ballTexture, gRenderer);
		// ballTexture.render(gRenderer, 100 ,10);
		// SDL_RenderCopy(gRenderer, ballTexture.mTexture, nullptr, nullptr);
		SDL_RenderPresent(gRenderer);
    }

    quit();
}