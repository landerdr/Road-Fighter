//
// Created by lander on 19.01.19.
//

#include "PassingCarSFML.h"
#include "../Logic/Transformation.h"

PassingCarSFML::PassingCarSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("./Resources/PlayerCar.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());
    r_h = 0.1;
    r_w = 0.1;
    c_x = 0;
    c_y = -4;
}

void PassingCarSFML::run(int speed) {
    c_y += (speed-200)/4000.0;
    sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()), roadfighter::Transformation::Instance()->transY(getUpperY()));
}

void PassingCarSFML::draw() {
    window->draw(sprite);
}
