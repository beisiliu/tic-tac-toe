//
//  data.cpp
//  tic-tac-toe
//
//  Created by lewis on 2023/7/24.
//
#pragma once
#include <stdio.h>
#include <string>
#include <ctime>
#include <array>
#include <utility>
#include <SDL2/SDL.h>
#include "loadTexture.hpp"
#include "include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class Data
{
public:
    Data()
    {
        std::fstream settingJson("json/setting.json");
        setting = json::parse(settingJson);
    }
    std::string whoGoFirst()
    {
        time_t nowTime;
        if ( time(&nowTime) % 2 == 0 )
        {
            return "player";
        }
        return "computer";
    }

    bool isWin(int letter)
    {
        return (
            ( board[1] == letter and board [2] == letter and board[3] == letter ) or
            ( board[4] == letter and board [5] == letter and board[6] == letter ) or
            ( board[7] == letter and board [8] == letter and board[9] == letter ) or
            ( board[1] == letter and board [4] == letter and board[7] == letter ) or
            ( board[2] == letter and board [5] == letter and board[8] == letter ) or
            ( board[3] == letter and board [6] == letter and board[9] == letter ) or
            ( board[1] == letter and board [5] == letter and board[9] == letter ) or
            ( board[3] == letter and board [5] == letter and board[7] == letter )
        );
    }

    std::pair<int, int> postionXY(int x, int y)
    {
        std::pair<int, int> picPostion;
        // sheet 1
        if ( ( x > 0 and x < 100 ) and ( y > 200 and y < 300 ) ) 
        {
            return std::make_pair(30, 230);
        }
        // // sheet 2
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 3
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 4
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 5
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 6
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 7
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 8
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        // // sheet 9
        // if ( ( x > 10 and x < 20 ) and ( y > 30 and y < 40 ) ) return std::make_pair(100, 200);
        return std::make_pair(0, 0);
    }

    void drawBoard(int playerLetter, int computerLetter, SDL_Renderer* gRenderer, LoadTexture loadTexture)
    {
        for (int i = 1; i < board.size(); ++i)
        {

            loadTexture.imgClipAndShow(gRenderer, setting["initCoordinate"]["1"]["x"], setting["initCoordinate"]["1"]["y"], playerLetter);          
        }
    }
    
private:
json setting;
};
