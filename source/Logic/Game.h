//
// Created by LanderDeRoeck on 28/07/2019.
//

#ifndef ROAD_FIGHTER_GAME_H
#define ROAD_FIGHTER_GAME_H

#include "Configuration.h"
#include "HighSoreModule.h"
#include "World.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <type_traits>

namespace RoadFighter {
enum GameState
{
        Menu,
        Playing,
        VictoryScreen
};

class Game
{
protected:
        // Used to check if the program is running
        bool running = true;
        // Target fps, gets overridden by config file
        int target_fps;
        // Average fps, used to calculate fps on title bar
        double avg_fps;
        // Pointer to the world
        std::shared_ptr<World> world;
        // Score observer
        std::shared_ptr<RoadFighter::ScoreObserver> score;
        // Highscore module, used to save highest score
        RoadFighter::HighSoreModule h;
        // Game state used to track the game
        GameState state = Menu;
        // Used to automatically progress to the next stage after 10 sec
        std::chrono::steady_clock::time_point timePoint;
        // Level selector [-1, 0, 1]
        int selector = -1;

public:
        Game();
        /**
         * Starts the game
         */
        void run();

        // Virtual functions
        virtual void init_game() = 0;
        virtual void draw_menu() = 0;
        virtual void draw_screen() = 0;
        virtual void update_title() = 0;
        virtual void draw_victory() = 0;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_GAME_H
