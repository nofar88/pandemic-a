//
// Created by Liron on 28/04/2021.
//

#include "Medic.hpp"

pandemic::Player& pandemic::Medic::drive(pandemic::City city) {

    return *this;
}

pandemic::Player& pandemic::Medic::fly_direct(pandemic::City city) {

    return *this;
}

pandemic::Player& pandemic::Medic::fly_charter(pandemic::City city) {

    return *this;
}

pandemic::Player& pandemic::Medic::fly_shuttle(pandemic::City city) {

    return *this;
}

pandemic::Player& pandemic::Medic::treat(pandemic::City) {

    return *this;
}

void pandemic::Medic::tryTreat() {

}

string pandemic::Medic::role() {
    return "Medic";
}
