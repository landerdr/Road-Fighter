//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORY_H
#define ROAD_FIGHTER_ABSTRACTFACTORY_H


#include "Entity.h"
#include "PlayerCar.h"
#include "PassingCar.h"
#include "RacingCar.h"
#include "Bullet.h"

namespace roadfighter {
    class AbstractFactory {
    public:
        virtual std::shared_ptr<roadfighter::PlayerCar> createPlayerCar(float x, float y) = 0;
        virtual std::shared_ptr<roadfighter::PassingCar> createPassingCar(float x, float y) = 0;
        virtual std::shared_ptr<roadfighter::RacingCar> createRacingCar(float x, float y) = 0;
        virtual std::shared_ptr<roadfighter::Bullet> createBullet(float x, float y) = 0;
    };
}



#endif //ROAD_FIGHTER_ABSTRACTFACTORY_H
