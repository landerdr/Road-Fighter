//
// Created by lander on 17.01.19.
//

#include "AbstractFactorySFML.h"
#include "PassingCarSFML.h"
#include "RacingCarSFML.h"
#include "BulletSFML.h"

AbstractFactorySFML::AbstractFactorySFML(std::shared_ptr<sf::RenderWindow> &window) : window(window) {

}

std::shared_ptr<roadfighter::PlayerCar> AbstractFactorySFML::createPlayerCar(float x, float y) {
    return std::make_shared<PlayerCarSFML>(window, x, y);
}

std::shared_ptr<roadfighter::PassingCar> AbstractFactorySFML::createPassingCar(float x, float y) {
    return std::make_shared<PassingCarSFML>(window, x, y);
}

std::shared_ptr<roadfighter::RacingCar> AbstractFactorySFML::createRacingCar(float x, float y) {
    return std::make_shared<RacingCarSFML>(window, x, y);
}

std::shared_ptr<roadfighter::Bullet> AbstractFactorySFML::createBullet(float x, float y) {
    return std::make_shared<BulletSFML>(window, x, y);
}
