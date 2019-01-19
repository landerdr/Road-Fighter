//
// Created by lander on 12/10/18.
//

#include "RacingCar.h"
#include "Random.h"

void roadfighter::RacingCar::run() {

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
