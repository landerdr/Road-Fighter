//
// Created by lander on 17.01.19.
//

#ifndef ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
#define ROAD_FIGHTER_ABSTRACTFACTORYSFML_H


#include "PlayerCarSFML.h"
#include "../Logic/AbstractFactory.h"

class AbstractFactorySFML : public roadfighter::AbstractFactory {
    std::shared_ptr<sf::RenderWindow> window;
public:
    explicit AbstractFactorySFML(std::shared_ptr<sf::RenderWindow> &window);
    std::shared_ptr<roadfighter::PlayerCar> createPlayerCar() override;
    std::shared_ptr<roadfighter::PassingCar> createPassingCar() override;
    std::shared_ptr<roadfighter::RacingCar> createRacingCar() override;
    std::shared_ptr<roadfighter::Bullet> createBullet() override;
};

#endif //ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
