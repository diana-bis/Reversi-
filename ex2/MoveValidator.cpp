//
// Created by Diana on 06/12/2024.
//

#include "MoveValidator.h"

MoveValidator::MoveValidator(Board& board) : board(board) {}

bool MoveValidator::isValidMove(int row, int col, char player) const {
    if(board.getCell(row, col) != 'O') {
        return false;
    }

    int directions[8][2] = { // All possible directions - 8 directions, 2 values per direction
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},            { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    for (int i = 0; i < 8; i++) {
        if (isDirectionValid(row, col, directions[i][0], directions[i][1], player)) {
            return true;
        }
    }
    return false;
}

void MoveValidator::executeMove(int row, int col, char player) {
    board.setCell(row, col, player);    // Place the player's piece

    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},            { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    // Flip pieces in all valid directions
    for (int i = 0; i < 8; i++) {
        if (isDirectionValid(row, col, directions[i][0], directions[i][1], player)) {
            flipInDirection(row, col, directions[i][0], directions[i][1], player);
        }
    }
}


bool MoveValidator::isDirectionValid(int row, int col, int dRow, int dCol, char player) const {
    //dRow - Indicates how many steps to move up or down
    //dCol - Indicates how many steps to move left or right
    int currentRow = row + dRow;
    int currentCol = col + dCol;

    char opponent = (player == 'B')? 'W' : 'B';
    bool wasOpponentPieceFound = false;

    while (currentRow >= 0 && currentRow < 8 && currentCol >= 0 && currentCol < 8) {
        char cell = board.getCell(currentRow, currentCol);
        if (cell == opponent) {
            wasOpponentPieceFound = true;  //Found opponent's piece
        }
        else if(cell == player) {
            return wasOpponentPieceFound;   //Valid if there was at least one opponent piece
        }
        else {
            break;  //Empty spot - not valid direction
        }
        currentRow += dRow;
        currentCol += dCol;
    }
    return false;
}

void MoveValidator::flipInDirection(int row, int col, int dRow, int dCol, char player) {
    int currentRow = row + dRow;
    int currentCol = col + dCol;

    while (currentRow >= 0 && currentRow < 8 && currentCol >= 0 && currentCol < 8) {
        char cell = board.getCell(currentRow, currentCol);
        if (cell == player) {
            return; // Stop flipping when player's piece is reached
        }
        board.setCell(currentRow, currentCol, player);

        // Move to the next cell in the same direction
        currentRow += dRow;
        currentCol += dCol;
    }
}
