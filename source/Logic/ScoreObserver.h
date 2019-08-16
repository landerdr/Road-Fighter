//
// Created by lander on 18.01.19.
//

#ifndef ROAD_FIGHTER_SCOREOBSERVER_H
#define ROAD_FIGHTER_SCOREOBSERVER_H

#include "World.h"
#include <memory>

namespace RoadFighter {
class World;
class ScoreObserver
{
        int score = 0;
        std::shared_ptr<RoadFighter::World> subject;

public:
        explicit ScoreObserver(std::shared_ptr<RoadFighter::World> subject);
        /**
         * Returns score
         * @return
         */
        int getScore() const;
        /**
         * Calculates score
         */
        void update();
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_SCOREOBSERVER_H
