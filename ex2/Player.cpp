//
// Created by Diana on 06/12/2024.
//

#include "Player.h"

// The game begins with 2 discs for each color
Player::Player(char color) : color(color), score(2) {}

char Player::getColor() const {
    return color;
}

int Player::getScore() const {
    return score;
}

void Player::updateScore(int newScore) {
    score = newScore;
}

