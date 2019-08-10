//
// Created by lander on 12/21/18.
//

#include "GameSFML.h"
#include "../Logic/Transformation.h"
#include <iomanip>
#include <sstream>

/*
 * TODO
 * make title screen:
 * input area for name, selector for level (level 1, ...)
 *
 * pause screen:
 * black screen, progress on level, restart, quit (to home screen)
 *
 * cars change scaling
 *
 * redo moving logic
 *
 * boss level
 *
 * exception class (std::exception as base)
 *
 * create logic control
 *
 * each entity keeps own distance
 */
void GameSFML::draw_screen()
{
        window->clear();

        // do something
        std::unique_ptr<sf::Event> event = std::make_unique<sf::Event>();
        while (window->pollEvent(*event)) {
                if (event->type == sf::Event::Closed ||
                    (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Escape)) {
                        h.save(world->getScore());
                        window->close();
                        running = false;
                }
        }
        // Check keyboard input
        world->handleInput();
        world->run();
        world->draw();
        window->display();
}
void GameSFML::init_game()
{
        world = std::make_shared<WorldSFML>(window);
        score = std::make_shared<RoadFighter::ScoreObserver>(world);
        world->attach(score);
}
void GameSFML::update_title()
{
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << avg_fps;
        std::string s = stream.str();

        window->setTitle("Racing Game - " + s + " FPS");
}
void GameSFML::draw_menu()
{
        window->clear();

        // do something
        std::unique_ptr<sf::Event> event = std::make_unique<sf::Event>();
        while (window->pollEvent(*event)) {
                if (event->type == sf::Event::Closed ||
                    (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Escape)) {
                        window->close();
                        running = false;
                } else if (event->type == sf::Event::KeyPressed) {
                        if (event->key.code == sf::Keyboard::Key::Z && selector > -1) {
                                selector -= 1;
                                std::cout << "one up" << std::endl;
                        } else if (event->key.code == sf::Keyboard::Key::S && selector < 1) {
                                selector += 1;
                                std::cout << "one down" << std::endl;
                        }
                }
        }

        window->draw(level1);
        window->draw(level2);
        window->draw(level3);

        indicator.setPosition(RoadFighter::Transformation::Instance()->transX(-2),
                              RoadFighter::Transformation::Instance()->transY(selector * 1.5));

        window->draw(indicator);

        window->display();
}
GameSFML::GameSFML()
{
        unsigned int x = RoadFighter::Configuration::Instance()->getWidth();
        unsigned int y = RoadFighter::Configuration::Instance()->getHeight();

        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(x, y), "Racing Game");
        //    window->setVerticalSyncEnabled(false);
        RoadFighter::Transformation::Instance()->setSize(window->getSize().x, window->getSize().y);


        font.loadFromFile("./Resources/ARCADECLASSIC.ttf");

        level1 = sf::Text("Level 1", font);
        level1.setCharacterSize(60);
        level1.setPosition(RoadFighter::Transformation::Instance()->transX(-1),
                           RoadFighter::Transformation::Instance()->transY(-1.5));
        level1.setStyle(sf::Text::Bold);

        level2 = sf::Text("Level 2", font);
        level2.setCharacterSize(60);
        level2.setPosition(RoadFighter::Transformation::Instance()->transX(-1),
                           RoadFighter::Transformation::Instance()->transY(0));
        level2.setStyle(sf::Text::Bold);

        level3 = sf::Text("Level 3", font);
        level3.setCharacterSize(60);
        level3.setPosition(RoadFighter::Transformation::Instance()->transX(-1),
                           RoadFighter::Transformation::Instance()->transY(1.5));
        level3.setStyle(sf::Text::Bold);

        indicator.setSize(sf::Vector2f(5, 5));
        indicator.setScale(RoadFighter::Transformation::Instance()->getScaleX(),
                           RoadFighter::Transformation::Instance()->getScaleY());
        indicator.setFillColor(sf::Color::White);
}
