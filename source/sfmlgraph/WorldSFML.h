//
// Created by lander on 1/2/19.
//

#ifndef ROAD_FIGHTER_WORLDSFML_H
#define ROAD_FIGHTER_WORLDSFML_H


#include <SFML/Graphics.hpp>
#include "../Logic/World.h"
#include "PlayerCarSFML.h"
#include "PassingCarSFML.h"

class WorldSFML : public roadfighter::World {
    int distance = 0;
    int finish = 20000;
    int speed = 0;
    sf::Font font;
    sf::Texture texture;
    sf::Text score_1;
    sf::Text score_2;
    sf::Text speed_1;
    sf::Text speed_2;
    sf::Sprite sprite;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<PlayerCarSFML> player;
    std::set<std::shared_ptr<PassingCarSFML>> Entities;
public:
    explicit WorldSFML(const std::shared_ptr<sf::RenderWindow> &window);
    void draw() override;
    void run() override;
};


#endif //ROAD_FIGHTER_WORLDSFML_H
