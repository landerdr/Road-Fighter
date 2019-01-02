//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include "Logic/PlayerCar.h"
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
    if (!texture.loadFromFile("../Resources/TestRoad.png"))
        return;
    sf::Sprite road(texture);
    road.setScale(4,4);
    road.setPosition(150, 0);

    sf::Texture texture2;
    if (!texture2.loadFromFile("../Resources/TestCar.png"))
        return;
    sf::Sprite car(texture2);
    car.setScale(4,4);
    PlayerCar car1;
    car.setPosition((car1.getUpperCorner_X()+4)*100, (car1.getUpperCorner_Y()+3)*100);


    sf::Font font;
    font.loadFromFile("../Resources/ARCADECLASSIC.ttf");

    sf::Text text("Score", font);
    text.setCharacterSize(30);
    text.setPosition(600, 30);
    text.setStyle(sf::Text::Bold);

    sf::Text score("00000", font);
    score.setCharacterSize(30);
    score.setPosition(620, 60);
    score.setStyle(sf::Text::Bold);


    for (int i = -1; i<3; i++){
        road.setPosition(150, i*200);
        App.draw(road);
    }
    App.draw(car);
    App.draw(text);
    App.draw(score);

    auto next_frame = std::chrono::steady_clock::now();
    int k = 0;
    while(App.isOpen()) {
        k = (k+1)%200;
        App.clear();
        // calculates end of frame
        next_frame += std::chrono::microseconds(1000000 / fps);

        // do something
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed || (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Key::Escape)) {
                App.close();
            }
        }
        //Check keyboard input
        car1.m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

        car1.m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);

        car1.run();
        car.setPosition((car1.getUpperCorner_X()+4)*100, (car1.getUpperCorner_Y()+3)*100);

        for (int i = -1; i<3; i++){
            road.setPosition(150, i*200+k);
            App.draw(road);
        }
        App.draw(road);
        App.draw(car);
        App.draw(text);
        App.draw(score);
        App.display();

//        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

Game::Game() {}

