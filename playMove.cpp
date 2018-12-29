//
//  playMove.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <tic-tac-toe/playMove.h>

using namespace std;

void playMove(int board[3][3], int row, int col, bool& turn, bool& validMove, bool& gameOver, int& winCode) {

    // If the game is over, do nothing
    if (gameOver) return;
    // Insert your code here
    if(board[row][col]==0)
        validMove = true;
    else
        validMove = false;
    
    if(validMove){
        if(turn)
            board[row][col]=1;
        else
            board[row][col]=-1;
    }
    if(board[0][0]==board[0][1] && board[0][1]==board[0][2] && board[0][0]!=0)
        winCode=1;
    if(board[1][0]==board[1][1] && board[1][1]==board[1][2] && board[1][0]!=0)
        winCode=2;
    if(board[2][0]==board[2][1] && board[2][1]==board[2][2] && board[2][0]!=0)
        winCode=3;
    if(board[0][0]==board[1][0] && board[1][0]==board[2][0] && board[0][0]!=0)
        winCode=4;
    if(board[0][1]==board[1][1] && board[1][1]==board[2][1] && board[0][1]!=0)
        winCode=5;
    if(board[0][2]==board[1][2] && board[1][2]==board[2][2] && board[0][2]!=0)
        winCode=6;
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=0)
        winCode=7;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=0)
        winCode=8;
     
    if(winCode!=0)
        gameOver=true;
     
    if(validMove){
        if(turn)
            turn=false;
        else
            turn=true;
    }
    
    //Checking for a draw 
    bool is_draw = true;
    for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(board[row][col]==0){
                    is_draw = false;
                }
                    
            }
        }
    if(is_draw)
        gameOver = true;
    

    // The function must always print the output specified in the handout before it exits
    // Use the standard output (i.e., cout) to print the output

    // Insert code to print the output below
    for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                cout<<board[row][col]<<" ";
                    
            }
        }
    cout<<row<<" "<<col<<" "<<turn<<" "<<validMove<<" "<<gameOver<<" "<<winCode<<endl;
}

