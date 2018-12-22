//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>

void Game::run() {
    /*
     * Reference used for limiting fps to defined value:
     * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
     */
    int fps = 60;
//    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);

    sf::Window App(sf::VideoMode(800, 600), "myproject");

    auto next_frame = std::chrono::steady_clock::now();

    while(App.isOpen()) {
        // calculates end of frame
        next_frame += std::chrono::milliseconds(1000 / fps);

        // do something
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();

//        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

Game::Game() {}

