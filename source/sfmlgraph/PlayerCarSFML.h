//
// Created by lander on 1/1/19.
//

#ifndef ROAD_FIGHTER_PLAYERCARSFML_H
#define ROAD_FIGHTER_PLAYERCARSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/PlayerCar.h"

class PlayerCarSFML : public roadfighter::PlayerCar {
    std::shared_ptr<sf::RenderWindow> window;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    explicit PlayerCarSFML(const std::shared_ptr<sf::RenderWindow> &window, float x, float y);

    void draw() override;
};


#endif //ROAD_FIGHTER_PLAYERCARSFML_H
