//
//  mouseEvent.hpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/21.
//

#ifndef mouseEvent_hpp
#define mouseEvent_hpp

#include <stdio.h>
#include <SDL2/SDL.h>


class LButton{
public:
    LButton();
    
    void handleEvent( SDL_Event e );
    
    int getLButtonDownX() { return mPostion.x; }
    int getLButtonDownY() { return mPostion.y; }
    
    static LButton* pLButtonInstance();
private:
    SDL_Point mPostion;
    static LButton* pLButton;
};

#endif /* mouseEvent_hpp */
