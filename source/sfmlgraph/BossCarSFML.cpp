//
// Created by LanderDeRoeck on 10/08/2019.
//

#include "BossCarSFML.h"

BossCarSFML::BossCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y) : window(window)
{
        texture.loadFromFile(RoadFighter::Configuration::Instance()->getPath("BossCar"));
        sprite.setTexture(texture);
        sprite.setScale(RoadFighter::Transformation::Instance()->getScaleX(),
                        RoadFighter::Transformation::Instance()->getScaleY());
        r_w = (texture.getSize().x * RoadFighter::Transformation::Instance()->getScaleX() * 4.0 / window->getSize().x);
        r_h = (texture.getSize().y * RoadFighter::Transformation::Instance()->getScaleY() * 3.0 / window->getSize().y);
        c_x = x;
        c_y = y;
}
void BossCarSFML::draw()
{
        sprite.setPosition(RoadFighter::Transformation::Instance()->transX(getLeftX()),
                           RoadFighter::Transformation::Instance()->transY(getUpperY()));
        sprite.setTexture(texture);
        window->draw(sprite);
}
