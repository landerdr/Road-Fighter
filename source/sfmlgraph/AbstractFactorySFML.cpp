//
// Created by lander on 17.01.19.
//

#include "AbstractFactorySFML.h"

#include "BossCarSFML.h"
#include "BulletSFML.h"
#include "PassingCarSFML.h"
#include "RacingCarSFML.h"
#include <utility>

AbstractFactorySFML::AbstractFactorySFML(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {}

std::shared_ptr<RoadFighter::PlayerCar> AbstractFactorySFML::createPlayerCar(double x, double y)
{
        return std::make_shared<PlayerCarSFML>(window, x, y);
}

std::shared_ptr<RoadFighter::PassingCar> AbstractFactorySFML::createPassingCar(double x, double y,
                                                                               RoadFighter::CarType t)
{
        return std::make_shared<PassingCarSFML>(window, x, y, t);
}

std::shared_ptr<RoadFighter::RacingCar> AbstractFactorySFML::createRacingCar(double x, double y)
{
        return std::make_shared<RacingCarSFML>(window, x, y);
}

std::shared_ptr<RoadFighter::Bullet> AbstractFactorySFML::createBullet(double x, double y)
{
        return std::make_shared<BulletSFML>(window, x, y);
}
std::shared_ptr<RoadFighter::RacingCar> AbstractFactorySFML::createBossCar(double x, double y)
{
        return std::make_shared<BossCarSFML>(window, x, y);
}
