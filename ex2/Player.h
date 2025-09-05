//
// Created by Diana on 06/12/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

//No need to implement big 5 since the default use is sufficient

// Class represents the player and their actions
class Player {

private:
    char color; // 'B' for Black, 'W' for White
    int score;

public:
    Player(char color);  // Constructor
    char getColor() const;  // Get the player's color
    int getScore() const;  // Get the player's score
    void updateScore(int newScore);  // Update the player's score

};



#endif //PLAYER_H
