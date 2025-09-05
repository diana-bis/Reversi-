//
// Created by Diana on 06/12/2024.
//

#ifndef BOARD_H
#define BOARD_H


//No need to implement big 5 since the default use is sufficient - no dynamic memory allocation used

//Class provides board information and sets cells
class Board {

private:
    char board[8][8];

public:
    Board();    // Constructor - Initializes the board with how it should be at the beginning of each game
    char getCell(int row, int col) const;   // Returns the value of a cell ('B', 'W', or 'o')
    void setCell(int row, int col, char value);   // Updates the value of a cell
    void printBoard() const;
    bool isFull() const;    // Checks if the board has no empty cells
    int calculateScore(char player) const;   // Counts the pieces of a specific player
};



#endif //BOARD_H
