//
// Created by lander on 18.01.19.
//

#ifndef ROAD_FIGHTER_SCOREOBSERVER_H
#define ROAD_FIGHTER_SCOREOBSERVER_H


#include <memory>
#include "World.h"

namespace roadfighter {
    class World;
    class ScoreObserver {
        int score = 0;
        std::shared_ptr<roadfighter::World> subject;
    public:
        explicit ScoreObserver(const std::shared_ptr<roadfighter::World> &subject);
        int getScore() const;
        void update();
    };
}



#endif //ROAD_FIGHTER_SCOREOBSERVER_H
