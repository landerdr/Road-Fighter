//
// Created by lander on 1/1/19.
//

#ifndef ROAD_FIGHTER_PLAYERCARSFML_H
#define ROAD_FIGHTER_PLAYERCARSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/PlayerCar.h"

class PlayerCarSFML : public roadfighter::PlayerCar {
public:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    PlayerCarSFML();
};


#endif //ROAD_FIGHTER_PLAYERCARSFML_H
