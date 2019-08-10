//
// Created by LanderDeRoeck on 28/07/2019.
//

#include "Game.h"

void RoadFighter::Game::run()
{
        /*
         * Reference used for limiting target_fps to defined value:
         * https://stackoverflow.com/questions/38730273/how-to-limit-fps-in-a-loop-with-c
         */

        // Sets required variables
        init_game();

        auto next_frame = std::chrono::steady_clock::now();

        // Calculating average target_fps
        auto fps_time = std::chrono::steady_clock::now();
        int actual_fps = 0;

        while (running) {
                // Calculates end of frame
                next_frame += std::chrono::microseconds(1000000 / target_fps);

                if (state == Menu) {
                        draw_menu();
                }
                else if (state == Playing) {
                        draw_screen();
                }

                // Avg target_fps calculation
                actual_fps += 1;

                if (std::chrono::steady_clock::now() - fps_time >= std::chrono::seconds(1)) {
                        fps_time = std::chrono::steady_clock::now();
                        avg_fps = 0.5 * avg_fps + 0.5 * actual_fps;
                        update_title();
                        actual_fps = 0;
                }

                // Wait for end of frame
                std::this_thread::sleep_until(next_frame);
        }
}
RoadFighter::Game::Game() {
        target_fps = static_cast<int>(RoadFighter::Configuration::Instance()->getFPS());
        avg_fps = static_cast<double>(target_fps);
}
