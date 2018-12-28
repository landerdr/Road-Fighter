//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include "PlayerCar.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>   

void Game::run() {
    /*
     * Reference used for limiting fps to defined value:
     * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
     */
    int fps = 100;
//    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), title);

    sf::RenderWindow App(sf::VideoMode(800, 600), "myproject");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("./Resources/Backdrop.png"))
        return;
    sf::Sprite road(texture);
    road.setScale(5,5);
    sf::Texture texture2;
    if (!texture2.loadFromFile("./Resources/PlayerCar.png"))
        return;
    sf::Sprite car(texture2);
    car.setScale(5,5);
    car.setPosition(300, 400);
    PlayerCar car1;

    App.draw(road);
    App.draw(car);

    auto next_frame = std::chrono::steady_clock::now();

    while(App.isOpen()) {
        App.clear();
        // calculates end of frame
        next_frame += std::chrono::microseconds(1000000 / fps);

        // do something
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                App.close();
            }
            else if (Event.type == sf::Event::KeyPressed) {
                if (Event.key.code == sf::Keyboard::Key::D) {
                    car1.move = 4;
                }
                else if (Event.key.code == sf::Keyboard::Key::A) {
                    car1.move = 3;
                }
            }
        }
        car1.run();
        car.setPosition(car1.xPos, 400);
        car1.move = 0;

        App.draw(road);
        App.draw(car);
        App.display();

//        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

Game::Game() {}

