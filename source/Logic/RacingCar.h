//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_RACINGCAR_H
#define ROAD_FIGHTER_RACINGCAR_H

#include "Entity.h"

namespace roadfighter {
class RacingCar : public Entity
{
protected:
        int speed = 0;

public:
        /**
         * Calculates virtual position on screen depending on playerspeed
         * @param speed
         */
        void run(int speed);
        /**
         * Moves car left if possible
         */
        void moveleft();
        /**
         * Moves car right if possible
         */
        void moveright();
        /**
         * Slows down car
         * @param speed
         */
        void slow(int speed);
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_RACINGCAR_H
