//
// Created by lander on 1/2/19.
//

#include "WorldSFML.h"
#include "../Logic/FileReader.h"
#include "../Logic/Random.h"
#include "AbstractFactorySFML.h"
#include "PassingCarSFML.h"
#include <utility>

WorldSFML::WorldSFML(std::shared_ptr<sf::RenderWindow>  window, const std::string& levelFile) : window(std::move(window))
{
        auto levelConfig = RoadFighter::FileReader(levelFile);
        factory = std::make_shared<AbstractFactorySFML>(WorldSFML::window);

        Player = factory->createPlayerCar(0, 0.5);

        if (levelConfig.getBool("Enemies")) {
                RaceCars.emplace(factory->createRacingCar(-1, 0));
                RaceCars.emplace(factory->createRacingCar(-1, 1));
                RaceCars.emplace(factory->createRacingCar(-0.5, -1));
        }
        if (levelConfig.getBool("Boss")) {
                RaceCars.emplace(factory->createBossCar(-0.5, -2));
        }

        finish = levelConfig.getInt("Finish");

        texture.loadFromFile(RoadFighter::Configuration::Instance()->getPath("Backdrop"));
        sprite.setTexture(texture);
        sprite.setScale(RoadFighter::Transformation::Instance()->getScaleX(),
                        RoadFighter::Transformation::Instance()->getScaleY());

        font.loadFromFile(RoadFighter::Configuration::Instance()->getPath("Font"));

        score_1 = sf::Text("Score", font);
        score_1.setCharacterSize(30);
        score_1.setPosition(RoadFighter::Transformation::Instance()->transX(2), 30);
        score_1.setStyle(sf::Text::Bold);

        score_2 = sf::Text("0", font);
        score_2.setCharacterSize(30);
        score_2.setPosition(RoadFighter::Transformation::Instance()->transX(2.2), 60);
        score_2.setStyle(sf::Text::Bold);

        speed_1 = sf::Text("Quick", font);
        speed_1.setCharacterSize(30);
        speed_1.setPosition(RoadFighter::Transformation::Instance()->transX(2), 90);
        speed_1.setStyle(sf::Text::Bold);

        speed_2 = sf::Text(std::to_string(speed) + "  kmph", font);
        speed_2.setCharacterSize(30);
        speed_2.setPosition(RoadFighter::Transformation::Instance()->transX(2.2), 120);
        speed_2.setStyle(sf::Text::Bold);
}

void WorldSFML::draw()
{
        // Drawing background
        for (int i = -1; i < 3; i++) {
                sprite.setPosition(
                    RoadFighter::Transformation::Instance()->transX(-2.5),
                    RoadFighter::Transformation::Instance()->transY(-3 + i * 2 + 0.01 * (distance % 200)));
                window->draw(sprite);
        }
        // Drawing passing cars
        for (auto& e : PassingCars) {
                e->draw();
        }
        // Drawing racing cars
        for (auto& e : RaceCars) {
                e->draw();
        }

        Player->draw();

        for (auto& e : Bullets) {
                e->draw();
        }

        // UI elements
        speed_2.setString(std::to_string(speed) + "  kmph");
        score_2.setString(std::to_string(score->getScore()));

        window->draw(score_1);
        window->draw(score_2);
        window->draw(speed_1);
        window->draw(speed_2);

        distance += speed / 100;
}

void WorldSFML::handleInput()
{
        Z = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
        Q = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
        S = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
        D = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
        Space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
