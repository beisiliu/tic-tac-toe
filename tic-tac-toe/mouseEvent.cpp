//
//  mouseEvent.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/21.
//

#include "mouseEvent.hpp"
LButton* LButton::pLButton = nullptr;
LButton* LButton::pLButtonInstance()
{
    if ( pLButton == nullptr )
    {
        pLButton = new LButton();
        return  pLButton;
    }
    return pLButton;
}

LButton::LButton()
{
    mPostion.x = 0;
    mPostion.y = 0;
}

void LButton::handleEvent( SDL_Event e )
{
    if ( e.type == SDL_MOUSEBUTTONDOWN )
    {
        SDL_GetMouseState(&mPostion.x, &mPostion.y);
    }
}
