//
// Created by lander on 19.01.19.
//

#include "PassingCarSFML.h"
#include "../Logic/Transformation.h"

PassingCarSFML::PassingCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y, roadfighter::CarType t)
    : window(window)
{
        type = t;
        if (type == roadfighter::Speed) {
                texture.loadFromFile("./Resources/PassingCar1.png");
        } else {
                texture.loadFromFile("./Resources/PassingCar.png");
        }
        sprite.setTexture(texture);
        sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),
                        roadfighter::Transformation::Instance()->getScaleY());
        r_w = (texture.getSize().x * roadfighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
        r_h = (texture.getSize().y * roadfighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
        c_x = x;
        c_y = y;
}

void PassingCarSFML::draw()
{
        sprite.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()),
                           roadfighter::Transformation::Instance()->transY(getUpperY()));
        sprite.setTexture(texture);
        window->draw(sprite);
}
