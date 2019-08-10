//
// Created by lander on 19.01.19.
//

#include "BulletSFML.h"

BulletSFML::BulletSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y) : window(window)
{
        shape.setSize(sf::Vector2f(2, 2));
        shape.setScale(RoadFighter::Transformation::Instance()->getScaleX(),
                       RoadFighter::Transformation::Instance()->getScaleY());
        r_w = (shape.getSize().x * RoadFighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
        r_h = (shape.getSize().y * RoadFighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
        c_x = x;
        c_y = y;
}

void BulletSFML::draw()
{
        shape.setPosition(RoadFighter::Transformation::Instance()->transX(getLeftX()),
                          RoadFighter::Transformation::Instance()->transY(getUpperY()));
        shape.setFillColor(sf::Color::Black);
        window->draw(shape);
}
