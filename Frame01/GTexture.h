#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>

#pragma once

class GTexture
{
	public:
		//Initializes variables
		GTexture();

		//Deallocates memory
		~GTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path ,SDL_Renderer* gRenderer);
        		
		//Renders texture at given point
		void render( SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		
		//Deallocates texture
		void free();

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};
