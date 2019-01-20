//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORY_H
#define ROAD_FIGHTER_ABSTRACTFACTORY_H

#include "Bullet.h"
#include "Entity.h"
#include "PassingCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"

namespace roadfighter {
class AbstractFactory
{
public:
        virtual std::shared_ptr<roadfighter::PlayerCar> createPlayerCar(float x, float y) = 0;
        virtual std::shared_ptr<roadfighter::PassingCar> createPassingCar(float x, float y, int t) = 0;
        virtual std::shared_ptr<roadfighter::RacingCar> createRacingCar(float x, float y) = 0;
        virtual std::shared_ptr<roadfighter::Bullet> createBullet(float x, float y) = 0;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_ABSTRACTFACTORY_H
