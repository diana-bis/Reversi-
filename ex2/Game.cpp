//
// Created by Diana on 06/12/2024.
//

#include "Game.h"

#include <iostream>

Game::Game() : validator(board), player1('B'), player2('W'), currentPlayer(&player1) {}

void Game::start() {
    bool playerChoseQuit = false;
    bool lastTurnChosePass = false;

    while (!playerChoseQuit && !board.isFull()) {
        board.printBoard();

        std::cout << currentPlayer->getColor() << ":" << std::endl;
        std::string input;
        std::cin >> input;


        if(input == "PASS") {
            std::cout << currentPlayer->getColor() << ": " << "PASS" << std::endl;

            // If last player chose pass and current player also chose pass - game ends, output winner
            if(lastTurnChosePass) {
                break;
            }
            lastTurnChosePass = true;
            switchPlayer();
            continue;
        }

        // When choosing quit the opponent is the winner
        if (input == "QUIT") {
            std::cout << currentPlayer->getColor() << ": " << "QUIT" << std::endl;
            switchPlayer();
            std::cout << currentPlayer->getColor() << " wins the game.\n";
            playerChoseQuit = true;
            break;  // Exit loop
        }

        // Get player input
        int row, col;
        if (!getPlayerInput(input, row, col)) {
            std::cout << "Invalid move; the game awaits a valid move.\n";
            continue;
        }

        // Check if move is valid
        if (!validator.isValidMove(row, col, currentPlayer->getColor())) {
            std::cout << "Invalid move; the game awaits a valid move.\n";
            continue;
        }

        // Execute the move and update the board
        validator.executeMove(row, col, currentPlayer->getColor());

        updatePlayerScore();
        lastTurnChosePass = false;
        switchPlayer();
    }
    if (!playerChoseQuit) {
        announceWinner();
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void Game::updatePlayerScore() {
    int score1 = board.calculateScore(player1.getColor());
    int score2 = board.calculateScore(player2.getColor());
    player1.updateScore(score1);
    player2.updateScore(score2);
}

void Game::announceWinner() const {
    int score1 = player1.getScore();
    int score2 = player2.getScore();

    if (score1 > score2) {
        std::cout << player1.getColor() << " wins the game.\n";
    }
    else if (score2 > score1) {
        std::cout << player2.getColor() << " wins the game.\n";
    }
    else {
        std::cout << "The game ends in a tie.\n";
    }
}

bool Game::getPlayerInput(const std::string &input, int &row, int &col) {
    if (input.length() != 2) {
        return false; // Invalid length
    }

    // First char must be a letter between A and H
    if (!isalpha(input[0]) || toupper(input[0]) < 'A' || toupper(input[0]) > 'H') {
        return false;
    }
    col = input[0] - 'A'; // Convert 'A'-'H' to 0-7

    // Second character must be a digit between 0 and 7
    if (!isdigit(input[1]) || (input[1] - '0' < 1 || input[1] - '0' > 8)) {
        return false;
    }
    row = (input[1] - '0')-1; // Convert '1'-'8' to 0-7

    return true;
}
