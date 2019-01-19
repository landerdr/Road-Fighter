//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_PLAYERFACTORYSFML_H
#define ROAD_FIGHTER_PLAYERFACTORYSFML_H


#include "../Logic/PlayerFactory.h"
#include "PlayerCarSFML.h"

class PlayerFactorySFML : public roadfighter::PlayerFactory {
    sf::Texture texture;
    std::shared_ptr<sf::RenderWindow> window;
public:
    explicit PlayerFactorySFML(std::shared_ptr<sf::RenderWindow> &window);
    std::shared_ptr<PlayerCarSFML> create();
};


#endif //ROAD_FIGHTER_PLAYERFACTORYSFML_H
