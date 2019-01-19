//
// Created by lander on 19.01.19.
//

#include "RacingCarSFML.h"
#include "../Logic/Transformation.h"
#include "../Logic/Random.h"

void RacingCarSFML::run(int speed) {
    if (RacingCarSFML::speed < 400) {
        RacingCarSFML::speed += 1;
    }
    int movement = roadfighter::Random::Instance()->getInt() % 3;

    if (movement == 0) {
        moveleft();
    }
    else if (movement == 1) {
        moveright();
    }

    c_y += (speed-RacingCarSFML::speed)/4000.0;
}

void RacingCarSFML::draw() {
    sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()), roadfighter::Transformation::Instance()->transY(getUpperY()));
    window->draw(sprite);
}

RacingCarSFML::RacingCarSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    texture.loadFromFile("./Resources/PlayerCar.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());
    r_h = 0.1;
    r_w = 0.1;
    c_x = -1;
    c_y = 0;
}
