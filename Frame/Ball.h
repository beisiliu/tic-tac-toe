#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include "GTexture.h"

#pragma once

class Ball
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;
        
		//Initializes the variables
		Ball();

		~Ball();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move(int SCREEN_WIDTH, int SCREEN_HEIGHT);

		//Shows the dot on the screen
		void render(GTexture gBallTexture, SDL_Renderer* gRenderer);

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};