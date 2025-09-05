//
// Created by Diana on 06/12/2024.
//

#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "Board.h"

//No need to implement big 5 since the default use is sufficient

//Class provides information about valid moves and executes moves accordingly
class MoveValidator {
private:
    Board& board; // Reference to the board

    // Helper function to validate a direction
    bool isDirectionValid(int row, int col, int dRow, int dCol, char playerColor) const;

    // Helper function to flip pieces in a direction
    void flipInDirection(int row, int col, int dRow, int dCol, char playerColor);

public:
    MoveValidator(Board& board);  // Constructor
    bool isValidMove(int row, int col, char player) const;  // Check if a move is valid
    void executeMove(int row, int col, char player);    // Execute a move and flip pieces

};



#endif //MOVEVALIDATOR_H
