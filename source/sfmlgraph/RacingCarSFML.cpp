//
// Created by lander on 19.01.19.
//

#include "RacingCarSFML.h"
#include "../Logic/Random.h"
#include "../Logic/Transformation.h"

RacingCarSFML::RacingCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y) : window(window)
{
        texture.loadFromFile("./Resources/RaceCar.png");
        sprite.setTexture(texture);
        sprite.setScale(RoadFighter::Transformation::Instance()->getScaleX() / 2,
                        RoadFighter::Transformation::Instance()->getScaleY() / 2);
        r_w = (texture.getSize().x * RoadFighter::Transformation::Instance()->getScaleX() / 2 * 4.0 /
               window->getSize().x);
        r_h = (texture.getSize().y * RoadFighter::Transformation::Instance()->getScaleY() / 2 * 3.0 /
               window->getSize().y);
        c_x = x;
        c_y = y;
}

void RacingCarSFML::draw()
{
        sprite.setPosition(RoadFighter::Transformation::Instance()->transX(getLeftX()),
                           RoadFighter::Transformation::Instance()->transY(getUpperY()));
        sprite.setTexture(texture);
        window->draw(sprite);
}
