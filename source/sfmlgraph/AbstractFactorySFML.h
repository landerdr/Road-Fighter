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
    std::shared_ptr<roadfighter::PlayerCar> createPlayerCar(float x, float y) override;
    std::shared_ptr<roadfighter::PassingCar> createPassingCar(float x, float y, int t) override;
    std::shared_ptr<roadfighter::RacingCar> createRacingCar(float x, float y) override;
    std::shared_ptr<roadfighter::Bullet> createBullet(float x, float y) override;
};

#endif //ROAD_FIGHTER_ABSTRACTFACTORYSFML_H
