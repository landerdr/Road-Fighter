//
// Created by LanderDeRoeck on 10/08/2019.
//

#include "BossCar.h"
#include "Random.h"

bool RoadFighter::BossCar::hasShot() { return canShoot() && RoadFighter::Random::Instance()->getInt() % 2000 < 10; }
bool RoadFighter::BossCar::canShoot() { return shot + std::chrono::seconds(1) < std::chrono::steady_clock::now(); }
