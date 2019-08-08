//
// Created by lander on 1/2/19.
//

#ifndef ROAD_FIGHTER_WORLDSFML_H
#define ROAD_FIGHTER_WORLDSFML_H

#include "../Logic/World.h"
#include "AbstractFactorySFML.h"
#include "PassingCarSFML.h"
#include "PlayerCarSFML.h"
#include "RacingCarSFML.h"
#include <SFML/Graphics.hpp>

class WorldSFML : public roadfighter::World
{
        // Font data for text
        sf::Font font;
        // Texture data for background
        sf::Texture texture;
        // Text field for score
        sf::Text score_1;
        // Text field for actual score
        sf::Text score_2;
        // Text field for speed
        sf::Text speed_1;
        // Text field for actual speed
        sf::Text speed_2;
        // Sprite for background
        sf::Sprite sprite;
        // Pointer to game window
        std::shared_ptr<sf::RenderWindow> window;

public:
        /**
         * Creates world, loads in player and race cars, loads font data and texture data for background
         * @param window
         */
        explicit WorldSFML(const std::shared_ptr<sf::RenderWindow>& window);
        /**
         * Draws the world and all entities
         */
        void draw() override;
        /**
         * Checks keyboard input and puts internal control bools correct
         */
        void handleInput() override;
};

#endif // ROAD_FIGHTER_WORLDSFML_H
