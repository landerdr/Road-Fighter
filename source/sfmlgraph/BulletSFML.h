//
// Created by lander on 19.01.19.
//

#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/Bullet.h"

class BulletSFML : public roadfighter::Bullet {
    sf::RectangleShape shape;
    std::shared_ptr<sf::RenderWindow> window;
public:
    explicit BulletSFML(const std::shared_ptr<sf::RenderWindow> &window, float x, float y);
    void draw() override;
};


#endif //ROAD_FIGHTER_BULLETSFML_H
