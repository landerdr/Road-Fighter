//
// Created by lander on 1/2/19.
//

#include <cmath>
#include "WorldSFML.h"
#include "PlayerFactorySFML.h"
#include "../Logic/Transformation.h"
#include "PassingCarSFML.h"

WorldSFML::WorldSFML(const std::shared_ptr<sf::RenderWindow> &window) : window(window) {
    //PlayerFactorySFML pf(WorldSFML::window);
    player = std::make_shared<PlayerCarSFML> (WorldSFML::window); //pf.create();

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

    auto p = std::make_shared<PassingCarSFML>(PassingCarSFML(window));
    PassingCars.emplace(p);

    auto r = std::make_shared<RacingCarSFML>(RacingCarSFML(window));
    RaceCars.emplace(r);
}

void WorldSFML::draw() {
    for (int i = -1; i<3; i++){
        sprite.setPosition(roadfighter::Transformation::Instance()->transX(-2.5),
                roadfighter::Transformation::Instance()->transY(-3+i*2+0.01*(distance%200)));
        window->draw(sprite);
    }

    for(auto &e : PassingCars) {
        e->draw();
    }
    for(auto &e : RaceCars) {
        e->draw();
    }

    player->draw();

    window->draw(score_1);
    window->draw(score_2);
    window->draw(speed_1);
    window->draw(speed_2);

    distance += speed/100;
}

void WorldSFML::run() {
    if (distance > finish) {
        score_2.setString("10000");
        speed = 0;
        return;
    }
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

    player->m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
    player->m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
    player->run();
    for(auto &e : PassingCars) {
        e->run(speed);
    }
    for(auto &e : RaceCars) {
        e->run(speed);
    }

    speed_2.setString(std::to_string(speed) + "  kmph");
//    score->update();
//    score_2.setString(std::to_string(score->getScore()));
}

