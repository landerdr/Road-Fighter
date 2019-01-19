//
// Created by lander on 12/10/18.
//

#include "RacingCar.h"
#include "Random.h"

void roadfighter::RacingCar::run() {
    int movement = roadfighter::Random::Instance()->getInt() % 3;

    if (movement == 0) {
        moveleft();
    }
    else if (movement == 1) {
        moveright();
    }
}

void roadfighter::RacingCar::moveleft() {
    if (getLeftX() > -1.5) {
        c_x -= 0.02;
    }
}

void roadfighter::RacingCar::moveright() {
    if (getRightX() < 0.5) {
        c_x += 0.02;
    }
}
