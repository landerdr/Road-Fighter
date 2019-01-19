//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H


#include <set>
#include "Entity.h"
#include "PlayerCar.h"
#include "PassingCar.h"
#include "RacingCar.h"
#include "ScoreObserver.h"
#include "Bullet.h"

namespace roadfighter {
    class ScoreObserver;
    class World : public Entity {
    protected:
        int distance = 0;
        int finish = 20000;
        int speed = 0;
        std::shared_ptr<roadfighter::PlayerCar> Player;
        std::shared_ptr<roadfighter::Bullet> Bullet;
        std::set<std::shared_ptr<PassingCar>> PassingCars;
        std::set<std::shared_ptr<RacingCar>> RaceCars;
        std::shared_ptr<roadfighter::ScoreObserver> score;
    public:
        void attach(std::shared_ptr<roadfighter::ScoreObserver> &score);
        bool entityCollision(std::shared_ptr<roadfighter::Entity> ent1, std::shared_ptr<roadfighter::Entity> ent2);
    };
}



#endif //ROAD_FIGHTER_WORLD_H
