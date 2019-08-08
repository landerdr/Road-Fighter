//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
#define ROAD_FIGHTER_ABSTRACTFACTORYSFML_H

#include "../Logic/AbstractFactory.h"
#include "PlayerCarSFML.h"

class AbstractFactorySFML : public roadfighter::AbstractFactory
{
        std::shared_ptr<sf::RenderWindow> window;

public:
        explicit AbstractFactorySFML(std::shared_ptr<sf::RenderWindow>& window);
        std::shared_ptr<roadfighter::PlayerCar> createPlayerCar(double x, double y) override;
        std::shared_ptr<roadfighter::PassingCar> createPassingCar(double x, double y, roadfighter::CarType t) override;
        std::shared_ptr<roadfighter::RacingCar> createRacingCar(double x, double y) override;
        std::shared_ptr<roadfighter::Bullet> createBullet(double x, double y) override;
};

#endif // ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
