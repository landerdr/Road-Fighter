//
// Created by LanderDeRoeck on 10/08/2019.
//

#ifndef ROAD_FIGHTER_BOSSCARSFML_H
#define ROAD_FIGHTER_BOSSCARSFML_H

#include "../Logic/BossCar.h"
#include <SFML/Graphics.hpp>

class BossCarSFML : public RoadFighter::BossCar
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
        explicit BossCarSFML(const std::shared_ptr<sf::RenderWindow>& window, double x, double y);
        /**
         * Draws car on screen
         */
        void draw() override;
};

#endif // ROAD_FIGHTER_BOSSCARSFML_H
