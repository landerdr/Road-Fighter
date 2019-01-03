//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include "Logic/PlayerCar.h"
#include "Logic/Transformation.h"
#include "sfmlgraph/PlayerCarSFML.h"
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
    roadfighter::Transformation::Instance()->setSize(800, 600);
    // Load a sprite to display
    sf::Texture texture;
    texture.loadFromFile("./Resources/TestRoad.png");
    sf::Sprite road(texture);
    road.setScale(roadfighter::Transformation::Instance()->getScale(),roadfighter::Transformation::Instance()->getScale());

    PlayerCarSFML car;
    car.sprite.setScale(roadfighter::Transformation::Instance()->getScale(),roadfighter::Transformation::Instance()->getScale());

    car.sprite.setPosition(roadfighter::Transformation::Instance()->transX(car.getUpperCorner_X()), roadfighter::Transformation::Instance()->transY(car.getUpperCorner_Y()));


    sf::Font font;
    font.loadFromFile("./Resources/ARCADECLASSIC.ttf");

    sf::Text text("Score", font);
    text.setCharacterSize(30);
    text.setPosition(roadfighter::Transformation::Instance()->transX(2), 30);
    text.setStyle(sf::Text::Bold);

    sf::Text score("00000", font);
    score.setCharacterSize(30);
    score.setPosition(roadfighter::Transformation::Instance()->transX(2.2), 60);
    score.setStyle(sf::Text::Bold);


    for (int i = -1; i<3; i++){
        road.setPosition(roadfighter::Transformation::Instance()->transX(-2.5), i*200);
        App.draw(road);
    }
    App.draw(car.sprite);
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
        car.m_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

        car.m_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);

        car.run();
        car.sprite.setPosition(roadfighter::Transformation::Instance()->transX(car.getUpperCorner_X()), roadfighter::Transformation::Instance()->transY(car.getUpperCorner_Y()));

        for (int i = -1; i<3; i++){
            road.setPosition(roadfighter::Transformation::Instance()->transX(-2.5), i*200+k);
            App.draw(road);
        }
        App.draw(road);
        App.draw(car.sprite);
        App.draw(text);
        App.draw(score);
        App.display();

//        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

Game::Game() {}

