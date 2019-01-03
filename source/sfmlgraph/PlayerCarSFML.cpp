//
// Created by lander on 1/1/19.
//

#include "PlayerCarSFML.h"

PlayerCarSFML::PlayerCarSFML() {
    texture.loadFromFile("./Resources/TestCar.png");
    sprite.setTexture(texture);
}
