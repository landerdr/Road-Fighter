//
// Created by lander on 12/10/18.
//

#include "PassingCar.h"

void RoadFighter::PassingCar::run(int speed)
{
        c_y -= (static_cast<int>(Configuration::Instance()->getPassingCarSpeed()) - speed) / 4000.0;
}

RoadFighter::CarType RoadFighter::PassingCar::getType() const { return type; }
