//
// Created by lander on 17.01.19.
//

#include "AbstractFactory.h"

roadfighter::AbstractFactory::AbstractFactory() {}

std::shared_ptr<roadfighter::Entity> roadfighter::AbstractFactory::create() {
    return std::shared_ptr<roadfighter::Entity>();
}

