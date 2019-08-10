//
// Created by LanderDeRoeck on 10/08/2019.
//

#include "BossCar.h"

bool RoadFighter::BossCar::hasShot()
{
        bool ret = canShoot();
        if (ret) {
                shot = std::chrono::steady_clock::now();
        }
        return ret;
}
bool RoadFighter::BossCar::canShoot() { return shot + std::chrono::seconds(1) < std::chrono::steady_clock::now(); }
