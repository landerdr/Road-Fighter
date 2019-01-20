//
// Created by lander on 19.01.19.
//

#ifndef ROAD_FIGHTER_BULLETSFML_H
#define ROAD_FIGHTER_BULLETSFML_H

#include "../Logic/Bullet.h"
#include <SFML/Graphics.hpp>

class BulletSFML : public roadfighter::Bullet
{
        // Bullet shape
        sf::RectangleShape shape;
        // Pointer to game window
        std::shared_ptr<sf::RenderWindow> window;

public:
        /**
         * Handles creation of bullet, loading texture etc
         * @param window
         * @param x
         * @param y
         */
        explicit BulletSFML(const std::shared_ptr<sf::RenderWindow>& window, float x, float y);
        /**
         * Draws bullet on window
         */
        void draw() override;
};

#endif // ROAD_FIGHTER_BULLETSFML_H
