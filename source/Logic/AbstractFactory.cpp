//
// Created by lander on 17.01.19.
//

#include "AbstractFactory.h"

AbstractFactory::AbstractFactory() {}

std::shared_ptr<roadfighter::Entity> AbstractFactory::create() {
    return std::shared_ptr<roadfighter::Entity>();
}

