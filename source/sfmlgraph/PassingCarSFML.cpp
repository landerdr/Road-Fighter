//
// Created by lander on 19.01.19.
//

#include "PassingCarSFML.h"

PassingCarSFML::PassingCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y,
                               RoadFighter::CarType t)
    : window(window)
{
        type = t;
        if (type == RoadFighter::Quick) {
                texture.loadFromFile(RoadFighter::Configuration::Instance()->getPath("PassingCar Quick"));
        } else {
                texture.loadFromFile(RoadFighter::Configuration::Instance()->getPath("PassingCar Slow"));
        }
        sprite.setTexture(texture);
        sprite.setScale(RoadFighter::Transformation::Instance()->getScaleX(),
                        RoadFighter::Transformation::Instance()->getScaleY());
        r_w = (texture.getSize().x * RoadFighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
        r_h = (texture.getSize().y * RoadFighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
        c_x = x;
        c_y = y;
}

void PassingCarSFML::draw()
{
        sprite.setPosition(RoadFighter::Transformation::Instance()->transX(getLeftX()),
                           RoadFighter::Transformation::Instance()->transY(getUpperY()));
        sprite.setTexture(texture);
        window->draw(sprite);
}
