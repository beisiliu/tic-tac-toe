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
#include "mainGame.hpp"

using json = nlohmann::json;

class Data
{
public:
    Data()
    {
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

    bool isWin(int letter, std::array<int, 10> board)
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

    int postionXY(int x, int y)
    {
        if ( ( x > 0 and x < 100 ) and ( y > 200 and y < 300 ) ) 
        {
            return 1;
        }

        if ( ( x > 100 and x < 200 ) and ( y > 200 and y < 300 ) ) 
        {
            return 2;
        }

        if ( ( x > 200 and x < 300 ) and ( y > 200 and y < 300 ) ) 
        {
            return 3;
        }

        if ( ( x > 0 and x < 100 ) and ( y > 100 and y < 200 ) ) 
        {
            return 4;
        }

        if ( ( x > 100 and x < 200 ) and ( y > 100 and y < 200 ) ) 
        {
            return 5;
        }

        if ( ( x > 200 and x < 300 ) and ( y > 100 and y < 200 ) ) 
        {
            return 6;
        }

        if ( ( x > 0 and x < 100 ) and ( y > 0 and y < 100 ) ) 
        {
            return 7;
        }

        if ( ( x > 100 and x < 200 ) and ( y > 0 and y < 100 ) ) 
        {
            return 8;
        }

        if ( ( x > 200 and x < 300 ) and ( y > 0 and y < 100 ) ) 
        {
            return 9;
        }

        return 0;
    }

    // board copy   
    std::array<int, 10> boardCopy(std::array<int, 10> board)
    {
        std::array<int, 10> boardCP;
        for (int i = 0; i < board.size(); ++i)
        {
            boardCP[i] = board[i];
        }
        return boardCP;
    }

    bool isSpaceFree(std::array<int, 10> board, int num)
    {
        if ( board[num] == 0 ) 
        {
            return true;
        }
        return false;
    }


    int computerRun(std::array<int, 10> board, int playerLetter, int computerLetter)
    {
        std::array<int, 10> copyBoard;
        // computer win
        for (int i = 1; i < board.size(); ++i)
        {
            copyBoard = boardCopy(board);
            copyBoard[i] = computerLetter;
            if ( isWin(computerLetter, copyBoard) )
            {
                if ( isSpaceFree(board, i) )
                {
                    return i;
                }
            }
        }

        // player win
        for (int i = 1; i < board.size(); ++i)
        {
            copyBoard = boardCopy(board);
            copyBoard[i] = playerLetter;
            if ( isWin(playerLetter, copyBoard) )
            {
                if ( isSpaceFree(board, i) )
                {
                    return i;
                }
            }
        }

        // 1,3,7,9四个角顺序走
        std::array<int, 4> num1_3_7_9 = { 1, 3, 7, 9 };
        for (int i = 0; i < 4; ++i) 
        {
            int num = num1_3_7_9[i];
            if (isSpaceFree(board, num)) 
            {
                return num;
            }
        }

        if (isSpaceFree(board, 5)) 
        {
            return 5;
        }

        // 2,4,6,8四个角顺序走
        std::array<int, 4> num2_4_6_8 = { 2, 4, 6, 8 };
        for (int i = 0; i < 4; ++i) 
        {
            int num = num2_4_6_8[i];
            if (isSpaceFree(board, num)) 
            {
                return num;
            }
        }

        return 0;
    }

    bool boardFull(std::array<int, 10> board)
    {
        for (int i = 1; i < board.size(); ++i)
        {
            if (board[i] == 0)
            {
                return false;
            }
        }
        return true;
    }

private:
};
