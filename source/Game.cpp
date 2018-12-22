//
// Created by lander on 12/21/18.
//


#include "Game.h"
#include <chrono>
#include <iostream>
#include <thread>

void Game::run() {
    /*
     * Reference used for limiting fps to defined value:
     * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
     */
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

