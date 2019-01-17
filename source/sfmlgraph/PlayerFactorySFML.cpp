//
// Created by lander on 17.01.19.
//

#include "PlayerFactorySFML.h"

PlayerFactorySFML::PlayerFactorySFML() {}

std::shared_ptr<roadfighter::Entity> PlayerFactorySFML::create() {
    return std::shared_ptr<PlayerCarSFML>();
}