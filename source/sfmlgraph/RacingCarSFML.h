//
// Created by vyolex on 19.01.19.
//

#ifndef ROAD_FIGHTER_RACINGCARSFML_H
#define ROAD_FIGHTER_RACINGCARSFML_H

#include "../Logic/RacingCar.h"
#include <SFML/Graphics.hpp>

class RacingCarSFML : public RoadFighter::RacingCar
{
        // Car sprite
        sf::Sprite sprite;
        // Car texture
        sf::Texture texture;
        // Pointer to game window
        std::shared_ptr<sf::RenderWindow> window;

public:
        /**
         * Creates car, loads texture etc
         * @param window
         * @param x
         * @param y
         */
        explicit RacingCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y);
        /**
         * Draws car on screen
         */
        void draw() override;
};

#endif // ROAD_FIGHTER_RACINGCARSFML_H
