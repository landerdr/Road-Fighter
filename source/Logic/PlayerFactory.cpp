//
// Created by lander on 17.01.19.
//

#include "PlayerFactory.h"

roadfighter::PlayerFactory::PlayerFactory() {}

std::shared_ptr<roadfighter::PlayerCar> roadfighter::PlayerFactory::create() {
    return std::shared_ptr<roadfighter::PlayerCar>();
}
