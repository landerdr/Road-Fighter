//
// Created by lander on 12/10/18.
//

#include "RacingCar.h"
#include "Random.h"

void roadfighter::RacingCar::moveleft()
{
        if (getLeftX() > -1.5) {
                c_x -= 0.02;
        }
}

void roadfighter::RacingCar::moveright()
{
        if (getRightX() < 0.5) {
                c_x += 0.02;
        }
}

void roadfighter::RacingCar::run(int speed)
{
        if (RacingCar::speed < 400) {
                RacingCar::speed += 1;
        } else if (RacingCar::speed > 600) {
                RacingCar::speed -= 1;
        }
        int movement = roadfighter::Random::Instance()->getInt() % 3;

        if (movement == 0) {
                moveleft();
        } else if (movement == 1) {
                moveright();
        }

        c_y += (speed - RacingCar::speed) / 4000.0;
}

void roadfighter::RacingCar::slow(int s) { speed = std::max(0, speed - s); }
