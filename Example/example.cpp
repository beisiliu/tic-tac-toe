#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <time.h>
#include <iostream>
#include <string>

//screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();

//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class LTexture
{
public:
    bool loadFromFile( std::string path);
private:
    SDL_Texture* gTexture;
    int mWidth;
    int mHeight;
};

class LButton
{
public:
private:
    SDL_Point mPosition;
    LButtonSprite mCurrentSprite;
}

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
LTexture gButtonSpriteSheetTexture;


bool LTexture::loadFromFile( std::string path)
{

    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load ( path.c_str() );
    if ( loadedSurface == nullptr )
    {
        printf( "Load img error %s , img path %s \n", IMG_GetError(), path.c_str() );
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if ( newTexture == nullptr )
        {
            printf( "Create Texture From Surface Error : %s \n", SDL_GetError() );
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    gTexture = newTexture;
    return gTexture != nullptr;
}


bool init()
{
    bool success = true;

    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0)
    {
        printf( "SDL Init Error : %s \n", SDL_GetError() );
        success = false;
    }
    else
    {
        // Create window
        gWindow = SDL_CreateWindow( "SDL Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( gWindow == nullptr )
        {
            printf( "SDL Create Window Error : %s \n", SDL_GetError() );
            success = false;
        }
        else
        {
            // Create Renderer
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if ( gRenderer == nullptr )
            {
                printf( "SDL Create Renderer Error : %s \n", SDL_GetError() );
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            }  
        }

    }

    return success;
}

bool loadMedia()
{
    bool success = true;
    if ( !gButtonSpriteSheetTexture.loadFromFile("button.png") )
    {
        printf( "load button png error \n" );
        success = false;
    }
    else
    {
        // Set sprites
        for ( int i = 0; i < BUTTON_SPRITE_TOTAL; ++i )
        {
            gSpriteClips[ i ].x = 0;
			gSpriteClips[ i ].y = i * 200;
			gSpriteClips[ i ].w = BUTTON_WIDTH;
			gSpriteClips[ i ].h = BUTTON_HEIGHT;
        }
    }

    return success;
}

int main( int argc, char* args[] )
{
    time_t startTime, endTime;
    startTime = clock();

    if ( !init() )
    {
        printf( "initialize error " );
    }
    else
    {

    }

    endTime = clock();

    std::cout << (double)(endTime-startTime)/CLOCKS_PER_SEC << std::endl;

}