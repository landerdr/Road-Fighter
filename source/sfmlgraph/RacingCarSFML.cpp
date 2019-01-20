//
// Created by lander on 19.01.19.
//

#include "RacingCarSFML.h"
#include "../Logic/Transformation.h"
#include "../Logic/Random.h"

RacingCarSFML::RacingCarSFML(const std::shared_ptr<sf::RenderWindow> &window, float x, float y) : window(window) {
    texture.loadFromFile("../Resources/RaceCar.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());
    r_w = static_cast<float> (texture.getSize().x * roadfighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
    r_h = static_cast<float> (texture.getSize().y * roadfighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
    c_x = x;
    c_y = y;
}

void RacingCarSFML::draw() {
    sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()), roadfighter::Transformation::Instance()->transY(getUpperY()));
    sprite.setTexture(texture);
    window->draw(sprite);
}
