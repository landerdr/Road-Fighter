//
// Created by lander on 17.01.19.
//

#include "AbstractFactorySFML.h"
#include "PassingCarSFML.h"
#include "RacingCarSFML.h"
#include "BulletSFML.h"

AbstractFactorySFML::AbstractFactorySFML(std::shared_ptr<sf::RenderWindow> &window) : window(window) {

}

std::shared_ptr<roadfighter::PlayerCar> AbstractFactorySFML::createPlayerCar() {
    return std::make_shared<PlayerCarSFML>(window);
}

std::shared_ptr<roadfighter::PassingCar> AbstractFactorySFML::createPassingCar() {
    return std::make_shared<PassingCarSFML>(window);
}

std::shared_ptr<roadfighter::RacingCar> AbstractFactorySFML::createRacingCar() {
    return std::make_shared<RacingCarSFML>(window);
}

std::shared_ptr<roadfighter::Bullet> AbstractFactorySFML::createBullet() {
    return std::make_shared<BulletSFML>(window);
}
