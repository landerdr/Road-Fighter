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
        void draw_screen() override;
        void init_game() override;
        void update_title() override;
        void draw_menu() override;
        void draw_victory() override;
};

#endif // ROAD_FIGHTER_GAMESFML_H
