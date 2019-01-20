//
// Created by lander on 1/2/19.
//

#include <cmath>
#include "WorldSFML.h"
#include "AbstractFactorySFML.h"
#include "../Logic/Transformation.h"
#include "PassingCarSFML.h"
#include "../Logic/Random.h"

WorldSFML::WorldSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    factory = std::make_shared<AbstractFactorySFML>(WorldSFML::window);

    Player = factory->createPlayerCar(0, 0.5);
    RaceCars.emplace(factory->createRacingCar(-1, 0));
    RaceCars.emplace(factory->createRacingCar(-1, 1));
    RaceCars.emplace(factory->createRacingCar(static_cast<float>(-0.5), -1));

    texture.loadFromFile("./Resources/TestRoad.png");
    sprite.setTexture(texture);
    sprite.setScale(roadfighter::Transformation::Instance()->getScaleX(),roadfighter::Transformation::Instance()->getScaleY());

    font.loadFromFile("./Resources/ARCADECLASSIC.ttf");

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
    speed_2.setString(std::to_string(speed) + "  kmph");
    score_2.setString(std::to_string(score->getScore()));

    window->draw(score_1);
    window->draw(score_2);
    window->draw(speed_1);
    window->draw(speed_2);

    distance += speed/100;
}

void WorldSFML::handleInput() {
    Z = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
    Q = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
    S = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
    D = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    Space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
