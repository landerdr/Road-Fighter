//
// Created by lander on 1/1/19.
//

#include "PlayerCarSFML.h"
#include "../Logic/Transformation.h"

PlayerCarSFML::PlayerCarSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("./Resources/TestCar.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());

    r_w = 0.2;
    r_h = static_cast<float> (2.0/3.0);
    c_x = 0;
    c_y = 1;
}

void PlayerCarSFML::draw() {
    sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()), roadfighter::Transformation::Instance()->transY(getUpperY()));
    window->draw(sprite);
}
