//
// Created by lander on 19.01.19.
//

#ifndef ROAD_FIGHTER_PASSINGCARSFML_H
#define ROAD_FIGHTER_PASSINGCARSFML_H

#include "../Logic/PassingCar.h"
#include <SFML/Graphics.hpp>

class PassingCarSFML : public RoadFighter::PassingCar
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
         * @param t
         */
        explicit PassingCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y,
                                RoadFighter::CarType t);
        /**
         * Draws car on window
         */
        void draw() override;
};

#endif // ROAD_FIGHTER_PASSINGCAR_H
