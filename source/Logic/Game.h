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

namespace roadfighter {
enum GameState {
        Menu,
        Playing,
        Paused
}
class Game
{
protected:
        bool running = true;
        int fps = 100;
        std::shared_ptr<World> world;
        std::shared_ptr<roadfighter::ScoreObserver> score;
        roadfighter::HighSoreModule h;
        roadfighter::Configuration config;

public:
        void run();
        virtual void init_game() = 0;
        virtual void draw_screen() = 0;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_GAME_H
