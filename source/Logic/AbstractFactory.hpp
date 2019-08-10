//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORY_HPP
#define ROAD_FIGHTER_ABSTRACTFACTORY_HPP

#include "BossCar.h"
#include "Bullet.h"
#include "Entity.h"
#include "PassingCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"

namespace RoadFighter {
class AbstractFactory
{
public:
        virtual std::shared_ptr<RoadFighter::PlayerCar> createPlayerCar(double x, double y) = 0;
        virtual std::shared_ptr<RoadFighter::PassingCar> createPassingCar(double x, double y, CarType t) = 0;
        virtual std::shared_ptr<RoadFighter::RacingCar> createRacingCar(double x, double y) = 0;
        virtual std::shared_ptr<RoadFighter::Bullet> createBullet(double x, double y) = 0;
        virtual std::shared_ptr<RoadFighter::BossCar> createBossCar(double x, double y) = 0;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_ABSTRACTFACTORY_HPP
