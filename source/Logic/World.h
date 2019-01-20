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
#include "AbstractFactory.h"
#include "Bullet.h"

namespace roadfighter {
    class ScoreObserver;
    class World : public Entity {
    protected:
        // Controls
        bool Z = false;
        bool Q = false;
        bool S = false;
        bool D = false;
        bool Space = false;

        unsigned int a_collisions = 0;
    public:
        unsigned int getA_collisions() const;

    protected:
        int distance = 0;
        int finish = 20000;
        int speed = 0;
        std::shared_ptr<roadfighter::PlayerCar> Player;
        std::shared_ptr<roadfighter::Bullet> Bullet;
        std::set<std::shared_ptr<PassingCar>> PassingCars;
        std::set<std::shared_ptr<RacingCar>> RaceCars;
        std::shared_ptr<roadfighter::AbstractFactory> factory;
        std::shared_ptr<roadfighter::ScoreObserver> score;
    public:
        int getDistance() const;
        int getFinish() const;
        int getSpeed() const;
        const std::shared_ptr<PlayerCar> &getPlayer() const;
        const std::set<std::shared_ptr<RacingCar>> &getRaceCars() const;
        void attach(std::shared_ptr<roadfighter::ScoreObserver> &score);
        std::tuple<bool, bool> entityCollision(std::shared_ptr<roadfighter::Entity> ent1, std::shared_ptr<roadfighter::Entity> ent2);
        void run() override;
        void randomEvent();
        void clearInput();
    };
}



#endif //ROAD_FIGHTER_WORLD_H
