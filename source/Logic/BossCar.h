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
        std::chrono::steady_clock::time_point shot;

        bool canShoot();
public:
        bool hasShot();
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_BOSSCAR_H
