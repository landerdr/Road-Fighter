//
// Created by LanderDeRoeck on 10/08/2019.
//

#ifndef ROAD_FIGHTER_BOSSCAR_H
#define ROAD_FIGHTER_BOSSCAR_H

#include "RacingCar.h"
#include <chrono>

namespace RoadFighter {
class BossCar : public RacingCar
{
protected:
        std::chrono::steady_clock::time_point shot = std::chrono::steady_clock::now();
        /**
         * Check if entity can shoot
         * @return
         */
        bool canShoot();

public:
        /**
         * Checks if entity has shot
         * @return
         */
        bool hasShot();
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_BOSSCAR_H
