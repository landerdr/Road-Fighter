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
        /**
         * Virtual constructor for Player
         * @param x
         * @param y
         * @return
         */
        virtual std::shared_ptr<RoadFighter::PlayerCar> createPlayerCar(double x, double y) = 0;
        /**
         * Virtual constructor for Passing car
         * @param x
         * @param y
         * @param t
         * @return
         */
        virtual std::shared_ptr<RoadFighter::PassingCar> createPassingCar(double x, double y, CarType t) = 0;
        /**
         * Virtual constructor for Computer controlled racing cars
         * @param x
         * @param y
         * @return
         */
        virtual std::shared_ptr<RoadFighter::RacingCar> createRacingCar(double x, double y) = 0;
        /**
         * Virtual constructor for Bullets
         * @param x
         * @param y
         * @return
         */
        virtual std::shared_ptr<RoadFighter::Bullet> createBullet(double x, double y) = 0;
        /**
         * Virtual constructor for Boss
         * @param x
         * @param y
         * @return
         */
        virtual std::shared_ptr<RoadFighter::RacingCar> createBossCar(double x, double y) = 0;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_ABSTRACTFACTORY_HPP
