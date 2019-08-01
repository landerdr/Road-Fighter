//
// Created by LanderDeRoeck on 28/07/2019.
//

#include "Game.h"

void roadfighter::Game::run()
{
        /*
         * Reference used for limiting fps to defined value:
         * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
         */

        // Sets required variables
        init_game();

        auto next_frame = std::chrono::steady_clock::now();

        while (running) {
                // Calculates end of frame
                next_frame += std::chrono::microseconds(1000000 / fps);

                // Draws the screen
                draw_screen();

                // Wait for end of frame
                std::this_thread::sleep_until(next_frame);
        }
}
