//
// Created by vyolex on 19.01.19.
//

#ifndef ROAD_FIGHTER_RACINGCARSFML_H
#define ROAD_FIGHTER_RACINGCARSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/RacingCar.h"

class RacingCarSFML : public roadfighter::RacingCar {
    sf::Sprite sprite;
    sf::Texture texture;
    std::shared_ptr<sf::RenderWindow> window;
public:
    RacingCarSFML(const std::shared_ptr<sf::RenderWindow> &window);

    void draw() override;
};


#endif //ROAD_FIGHTER_RACINGCARSFML_H
