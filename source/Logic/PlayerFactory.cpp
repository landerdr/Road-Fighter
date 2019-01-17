//
// Created by lander on 17.01.19.
//

#include "PlayerFactory.h"

PlayerFactory::PlayerFactory() {}

std::shared_ptr<roadfighter::Entity> PlayerFactory::create() {
    return std::shared_ptr<roadfighter::PlayerCar>();
}
