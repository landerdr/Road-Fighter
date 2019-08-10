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
enum GameState {
        Menu,
        Playing,
        Paused
};

class Game
{
protected:
        bool running = true;
        int target_fps = 100;
        double avg_fps;
        std::shared_ptr<World> world;
        std::shared_ptr<RoadFighter::ScoreObserver> score;
        RoadFighter::HighSoreModule h;
        GameState state = Menu;

public:
        Game();
        void run();
        virtual void init_game() = 0;
        virtual void draw_menu() = 0;
        virtual void draw_screen() = 0;
        virtual void update_title() = 0;
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_GAME_H
