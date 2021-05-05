//
// Created by Liron on 28/04/2021.
//


#include "Player.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace pandemic;

pandemic::Player &pandemic::Player::fly_direct(pandemic::City city) {

    return *this;
}

pandemic::Player &pandemic::Player::drive(pandemic::City city) {

    return *this;
}

pandemic::Player &pandemic::Player::fly_charter(pandemic::City city) {

    return *this;
}

pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City city) {

    return *this;
}

pandemic::Player &pandemic::Player::build() {

    return *this;

}


Player &Player::discover_cure(Color color, int n, bool ignoreStation, bool ignoreColor) {

    return *this;
}

pandemic::Player &pandemic::Player::discover_cure(pandemic::Color color) {
    return *this;
}

pandemic::Player &pandemic::Player::treat(pandemic::City city) {

    return *this;
}

pandemic::Player &pandemic::Player::take_card(pandemic::City city) {

    return *this;
}

string Player::role() {
    return std::string();
}

Player::Player(Board &board, City city) : board(board) {
    this->current = city;
}

