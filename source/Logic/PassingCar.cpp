//
// Created by lander on 12/10/18.
//

#include "PassingCar.h"

void roadfighter::PassingCar::run(int speed) { c_y += (speed - 200) / 4000.0; }

int roadfighter::PassingCar::getType() const { return type; }
