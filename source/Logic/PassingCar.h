//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H

#include "Entity.h"

namespace RoadFighter {
enum CarType
{
        Slow,
        Quick
};
class PassingCar : public Entity
{
protected:
        CarType type = Slow;

public:
        /**
         * Calculates virtual position on screen depending on player speed
         * @param speed
         */
        void run(int speed);
        /**
         * Returns type of passing car
         * @return
         */
        CarType getType() const;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_PASSINGCAR_H
