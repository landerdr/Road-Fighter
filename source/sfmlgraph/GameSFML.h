//
// Created by lander on 12/21/18.
//

#ifndef ROAD_FIGHTER_GAMESFML_H
#define ROAD_FIGHTER_GAMESFML_H

#include "../Logic/Game.h"
#include "WorldSFML.h"
#include <SFML/Graphics.hpp>

class GameSFML : public RoadFighter::Game
{
private:
        std::shared_ptr<sf::RenderWindow> window;

        // Menu section
        sf::Font font;
        sf::Text level1;
        sf::Text level2;
        sf::Text level3;
        sf::Text Victory;
        sf::Text score1;
        sf::Text score2;
        sf::RectangleShape indicator;

public:
        GameSFML();
        /**
         * Handles displaying game screen
         */
        void draw_screen() override;
        /**
         * Handles initialising the level
         */
        void init_game() override;
        /**
         * Updates program title (for fps)
         */
        void update_title() override;
        /**
         * Draws the selection menu for levels
         */
        void draw_menu() override;
        /**
         * Draws the victory screen
         */
        void draw_victory() override;
};

#endif // ROAD_FIGHTER_GAMESFML_H
