//
// Created by Diana on 06/12/2024.
//

#ifndef GAME_H
#define GAME_H

#include <string>

#include "Board.h"
#include "Player.h"
#include "MoveValidator.h"

//No need to implement big 5 since the default use is sufficient

// Class combines all classes together making them all work together to perform the game
class Game {
private:
    Board board;
    MoveValidator validator;
    Player player1;
    Player player2;
    Player* currentPlayer;

    void switchPlayer();    // Switch from current player to opponent
    void updatePlayerScore();   // Calculates the scores from the board and updates the players' scores
    void announceWinner() const;    // Determines and announces the winner based on the final scores
    bool getPlayerInput(const std::string &input, int &row, int &col); // Handle player input

public:
    Game();
    void start();
};



#endif //GAME_H
