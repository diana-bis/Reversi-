//
// Created by Diana on 06/12/2024.
//

#include "Board.h"

#include <iostream>
#include <ostream>

Board::Board() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            board[i][j] = 'O';
        }
    }
    board[3][3] = 'W'; // 4D - W
    board[4][4] = 'W'; // 5E - W
    board[4][3] = 'B'; // 5D - B
    board[3][4] = 'B'; // 4E - B

}

char Board::getCell(int row, int col) const {
    return board[row][col];
}

void Board::setCell(int row, int col, char value) {
    board[row][col] = value;
}

void Board::printBoard() const {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            std::cout << board[i][j];
            if (j < 7) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Board::isFull() const {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(board[i][j] == 'O') {
                return false;
            }
        }
    }
    return true;
}

int Board::calculateScore(char player) const {
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player) {
                score++;
            }
        }
    }
    return score;
}