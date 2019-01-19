//
// Created by lander on 17.01.19.
//

#include "PlayerFactorySFML.h"

PlayerFactorySFML::PlayerFactorySFML(std::shared_ptr<sf::RenderWindow> &window) {
    PlayerFactorySFML::window = window;
    texture.loadFromFile("./Resources/TestCar.png");
}

std::shared_ptr<PlayerCarSFML> PlayerFactorySFML::create() {
    PlayerCarSFML c(window);
    return std::shared_ptr<PlayerCarSFML>(&c);
}