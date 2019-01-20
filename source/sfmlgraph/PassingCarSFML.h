//
// Created by lander on 19.01.19.
//

#ifndef ROAD_FIGHTER_PASSINGCARSFML_H
#define ROAD_FIGHTER_PASSINGCARSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/PassingCar.h"

class PassingCarSFML : public roadfighter::PassingCar {
    sf::Sprite sprite;
    sf::Texture texture;
    std::shared_ptr<sf::RenderWindow> window;
public:
    explicit PassingCarSFML(const std::shared_ptr<sf::RenderWindow> &window, float x, float y, int t);
    void draw() override;
};


#endif //ROAD_FIGHTER_PASSINGCAR_H
