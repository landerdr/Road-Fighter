//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include "Logic/PlayerCar.h"
#include "Logic/Transformation.h"
#include "sfmlgraph/PlayerCarSFML.h"
#include "sfmlgraph/WorldSFML.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>   

void Game::run(unsigned int x, unsigned int y) {
    /*
     * Reference used for limiting fps to defined value:
     * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
     */
    int fps = 100;

    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(x, y), "Racing Game");
//    window->setVerticalSyncEnabled(false);
    roadfighter::Transformation::Instance()->setSize(window->getSize().x, window->getSize().y);

    auto world = std::make_shared<WorldSFML>(window);
    auto score = std::make_shared<roadfighter::ScoreObserver>(world);
    world->attach(score);

    auto next_frame = std::chrono::steady_clock::now();

    while(window->isOpen()) {
        window->clear();
        // calculates end of frame
        next_frame += std::chrono::microseconds(1000000 / fps);

        // do something
        std::unique_ptr<sf::Event> event = std::make_unique<sf::Event>();
        while (window->pollEvent(*event)) {
            if (event->type == sf::Event::Closed || (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Key::Escape)) {
                window->close();
            }
        }
        //Check keyboard input
        world->handleInput();
        world->run();
        world->draw();
        window->display();

//        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

