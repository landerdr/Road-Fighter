//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_PLAYERFACTORY_H
#define ROAD_FIGHTER_PLAYERFACTORY_H


#include "AbstractFactory.h"
#include "PlayerCar.h"

class PlayerFactory : public AbstractFactory {
public:
    PlayerFactory();
    std::shared_ptr<roadfighter::Entity> create();
};


#endif //ROAD_FIGHTER_PLAYERFACTORY_H
