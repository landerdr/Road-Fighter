//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_PLAYERFACTORYSFML_H
#define ROAD_FIGHTER_PLAYERFACTORYSFML_H


#include "../Logic/PlayerFactory.h"
#include "PlayerCarSFML.h"

class PlayerFactorySFML : public PlayerFactory {
public:
    PlayerFactorySFML();
    std::shared_ptr<roadfighter::Entity> create();
};


#endif //ROAD_FIGHTER_PLAYERFACTORYSFML_H
