//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include <chrono>
#include <iostream>
#include <thread>

void Game::run() {
    bool running = true;
    int fps = 60;

    auto next_frame = std::chrono::steady_clock::now();

    while(running) {
        next_frame += std::chrono::milliseconds(1000 / fps);

        // do stuff
        std::cout << std::time(nullptr) << '\n';

        // wait for end of frame
        std::this_thread::sleep_until(next_frame);
    }
}

Game::Game() {}

