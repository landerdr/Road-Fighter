//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
#define ROAD_FIGHTER_ABSTRACTFACTORYSFML_H

#include "../Logic/AbstractFactory.hpp"
#include "PlayerCarSFML.h"

class AbstractFactorySFML : public RoadFighter::AbstractFactory
{
        std::shared_ptr<sf::RenderWindow> window;

public:
        explicit AbstractFactorySFML(std::shared_ptr<sf::RenderWindow>  window);
        std::shared_ptr<RoadFighter::PlayerCar> createPlayerCar(double x, double y) override;
        std::shared_ptr<RoadFighter::PassingCar> createPassingCar(double x, double y, RoadFighter::CarType t) override;
        std::shared_ptr<RoadFighter::RacingCar> createRacingCar(double x, double y) override;
        std::shared_ptr<RoadFighter::Bullet> createBullet(double x, double y) override;
        std::shared_ptr<RoadFighter::RacingCar> createBossCar(double x, double y) override;
};

#endif // ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
