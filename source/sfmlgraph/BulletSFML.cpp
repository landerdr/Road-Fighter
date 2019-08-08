//
// Created by lander on 19.01.19.
//

#include "BulletSFML.h"
#include "../Logic/Transformation.h"

BulletSFML::BulletSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y) : window(window)
{
        shape.setSize(sf::Vector2f(2, 2));
        shape.setScale(roadfighter::Transformation::Instance()->getScaleX(),
                       roadfighter::Transformation::Instance()->getScaleY());
        r_w = (shape.getSize().x * roadfighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
        r_h = (shape.getSize().y * roadfighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
        c_x = x;
        c_y = y;
}

void BulletSFML::draw()
{
        shape.setPosition(roadfighter::Transformation::Instance()->transX(getLeftX()),
                          roadfighter::Transformation::Instance()->transY(getUpperY()));
        shape.setFillColor(sf::Color::Black);
        window->draw(shape);
}
