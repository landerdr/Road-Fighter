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

public:
        void draw_screen() override;
        void init_game() override;
        void update_title() override;
};

#endif // ROAD_FIGHTER_GAMESFML_H
