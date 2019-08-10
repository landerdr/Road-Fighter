//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_RACINGCAR_H
#define ROAD_FIGHTER_RACINGCAR_H

#include "Entity.h"

namespace RoadFighter {
class RacingCar : public Entity
{
protected:
        int speed = 0;

public:
        /**
         * Calculates virtual position on screen depending on playerspeed
         * @param playerspeed
         */
        void run(int playerspeed);
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
         * @param speedChange
         */
        void slow(int speedChange);

        virtual bool hasShot() { return false; };
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_RACINGCAR_H
