//
// Created by lander on 12/10/18.
//

#include "RacingCar.h"
#include "Random.h"

void RoadFighter::RacingCar::moveleft()
{
        if (getLeftX() > -1.5) {
                c_x -= 0.02;
        }
}

void RoadFighter::RacingCar::moveright()
{
        if (getRightX() < 0.5) {
                c_x += 0.02;
        }
}

void RoadFighter::RacingCar::run(int playerspeed)
{
        if (RacingCar::speed < Configuration::Instance()->getNormalSpeed()) {
                RacingCar::speed += 1;
        } else if (RacingCar::speed > Configuration::Instance()->getMaxSpeed()) {
                RacingCar::speed -= 1;
        }
        int movement = RoadFighter::Random::Instance()->getInt() % 3;

        if (movement == 0) {
                moveleft();
        } else if (movement == 1) {
                moveright();
        }

        c_y += (playerspeed - RacingCar::speed) / 4000.0;
}

void RoadFighter::RacingCar::slow(int speedChange) { speed = std::max(0, speed - speedChange); }
