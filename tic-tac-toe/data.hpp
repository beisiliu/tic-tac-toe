//
//  data.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/24.
//

#include <stdio.h>
#include <string>
#include <ctime>

std::string whoGoFirst(){
    time_t nowTime;
    if ( time(&nowTime) % 2 == 0 )
    {
        return "player";
    }
    return "computer";
}
