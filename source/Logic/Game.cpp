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

        // Calculating average fps
        auto fps_time = std::chrono::steady_clock::now();
        int actual_fps = 0;
        avg_fps = static_cast<double>(fps);

        while (running) {
                // Calculates end of frame
                next_frame += std::chrono::microseconds(1000000 / fps);

                // Draws the screen
                draw_screen();

                // Avg fps calculation
                actual_fps += 1;

                if (std::chrono::steady_clock::now() - fps_time > std::chrono::seconds(1)) {
                        fps_time = std::chrono::steady_clock::now();
                        avg_fps = 0.9 * avg_fps + 0.1 * actual_fps;
                        update_title();
                        actual_fps = 0;
                }

                // Wait for end of frame
                std::this_thread::sleep_until(next_frame);
        }
}
