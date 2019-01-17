//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORY_H
#define ROAD_FIGHTER_ABSTRACTFACTORY_H


#include "Entity.h"

class AbstractFactory {
public:
    AbstractFactory();
    virtual std::shared_ptr<roadfighter::Entity> create();
};


#endif //ROAD_FIGHTER_ABSTRACTFACTORY_H
