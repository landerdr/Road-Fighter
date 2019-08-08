//
// Created by lander on 18.01.19.
//

#ifndef ROAD_FIGHTER_SCOREOBSERVER_H
#define ROAD_FIGHTER_SCOREOBSERVER_H

#include "World.h"
#include <memory>

namespace roadfighter {
class World;
class ScoreObserver
{
        int score = 0;
        std::shared_ptr<roadfighter::World> subject;

public:
        explicit ScoreObserver(std::shared_ptr<roadfighter::World>  subject);
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
} // namespace roadfighter

#endif // ROAD_FIGHTER_SCOREOBSERVER_H
