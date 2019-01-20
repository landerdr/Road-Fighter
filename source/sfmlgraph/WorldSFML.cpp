//
// Created by lander on 1/2/19.
//

#include <cmath>
#include "WorldSFML.h"
#include "AbstractFactorySFML.h"
#include "../Logic/Transformation.h"
#include "PassingCarSFML.h"

WorldSFML::WorldSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    factory = std::make_shared<AbstractFactorySFML>(WorldSFML::window);

    Player = factory->createPlayerCar(0, 1);
    RaceCars.emplace(factory->createRacingCar(-1, 0));
    RaceCars.emplace(factory->createRacingCar(-1, 1));

    texture.loadFromFile("../Resources/TestRoad.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());

    font.loadFromFile("../Resources/ARCADECLASSIC.ttf");

    score_1 = sf::Text("Score", font);
    score_1.setCharacterSize(30);
    score_1.setPosition(roadfighter::Transformation::Instance()->transX(2), 30);
    score_1.setStyle(sf::Text::Bold);

    score_2 = sf::Text("0", font);
    score_2.setCharacterSize(30);
    score_2.setPosition(roadfighter::Transformation::Instance()->transX(2.2), 60);
    score_2.setStyle(sf::Text::Bold);

    speed_1 = sf::Text("Speed", font);
    speed_1.setCharacterSize(30);
    speed_1.setPosition(roadfighter::Transformation::Instance()->transX(2), 90);
    speed_1.setStyle(sf::Text::Bold);

    speed_2 = sf::Text(std::to_string(speed) + "  kmph", font);
    speed_2.setCharacterSize(30);
    speed_2.setPosition(roadfighter::Transformation::Instance()->transX(2.2), 120);
    speed_2.setStyle(sf::Text::Bold);

    PassingCars.emplace(factory->createPassingCar(0, -5));

//    Bullet = factory->createBullet();
}

void WorldSFML::draw() {
    // Drawing background
    for (int i = -1; i<3; i++){
        sprite.setPosition(roadfighter::Transformation::Instance()->transX(-2.5),
                roadfighter::Transformation::Instance()->transY(-3+i*2+0.01*(distance%200)));
        window->draw(sprite);
    }
    // Drawing passing cars
    for(auto &e : PassingCars) {
        e->draw();
    }
    // Drawing racing cars
    for(auto &e : RaceCars) {
        e->draw();
    }

    Player->draw();

    if (Bullet) {
        Bullet->draw();
    }

    // UI elements
    window->draw(score_1);
    window->draw(score_2);
    window->draw(speed_1);
    window->draw(speed_2);

    distance += speed/100;
}

void WorldSFML::run() {
    // Player passed finish
    if (distance > finish) {
        speed = 0;
        return;
    }
    // Handle keyboard input
    if (speed < 400 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        speed += 1;
    }
    if (speed < 600 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        speed += 1;
    }
    if (speed > 400 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        speed -= 1;
    }
    if (speed > 200 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        speed -= 1;
    }
    if (!Bullet && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        Bullet = factory->createBullet(Player->getC_x(), Player->getUpperY());
    }
    Player->setM_right(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D));
    Player->setM_left(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q));

    Player->run();

    for(auto it = PassingCars.begin(); it != PassingCars.end();) {
        (*it)->run(speed);
        if ((*it)->getUpperY() > 4) {
            it = PassingCars.erase(it);
        }
        else {
            ++it;
        }
    }
    for(auto &e : RaceCars) {
        e->run(speed);
    }

    if (Bullet) {
        Bullet->run();
        if (Bullet->getLowerY() < -4) {
            Bullet = nullptr;
        }
    }

    speed_2.setString(std::to_string(speed) + "  kmph");
    score->update();
    score_2.setString(std::to_string(score->getScore()));
}

