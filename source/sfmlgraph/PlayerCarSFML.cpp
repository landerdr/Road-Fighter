//
// Created by lander on 1/1/19.
//

#include "PlayerCarSFML.h"
#include "../Logic/Transformation.h"

PlayerCarSFML::PlayerCarSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("../Resources/TestCar.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());

    r_w = static_cast<float> (texture.getSize().x * roadfighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
    r_h = static_cast<float> (texture.getSize().y * roadfighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
    c_x = 0;
    c_y = 1;
}

void PlayerCarSFML::draw() {
    sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()), roadfighter::Transformation::Instance()->transY(getUpperY()));
    sprite.setTexture(texture);
    window->draw(sprite);
}
