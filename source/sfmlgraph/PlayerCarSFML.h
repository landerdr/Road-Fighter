//
// Created by lander on 1/1/19.
//

#ifndef ROAD_FIGHTER_PLAYERCARSFML_H
#define ROAD_FIGHTER_PLAYERCARSFML_H

#include "../Logic/PlayerCar.h"
#include <SFML/Graphics.hpp>

class PlayerCarSFML : public roadfighter::PlayerCar
{
        // Pointer to game window
        std::shared_ptr<sf::RenderWindow> window;
        // Car texture
        sf::Texture texture;
        // Car sprite
        sf::Sprite sprite;

public:
        /**
         * Creates car, loads texture etc
         * @param window
         * @param x
         * @param y
         */
        explicit PlayerCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y);
        /**
         * Draws car on screen
         */
        void draw() override;
};

#endif // ROAD_FIGHTER_PLAYERCARSFML_H
