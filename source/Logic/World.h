//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H

#include "AbstractFactory.h"
#include "Bullet.h"
#include "Entity.h"
#include "PassingCar.h"
#include "PlayerCar.h"
#include "RacingCar.h"
#include "ScoreObserver.h"
#include <set>

namespace roadfighter {
class ScoreObserver;
class World : public Entity
{
protected:
        // Controls
        bool Z = false;
        bool Q = false;
        bool S = false;
        bool D = false;
        bool Space = false;

        // Amount of collisions
        unsigned int a_collisions = 0;

        // Distance the player has traversed
        int distance = 0;
        // Distance from the finish line
        int finish = 20000;
        // Speed at which the player is traveling
        int speed = 0;
        // Pointer to Player
        std::shared_ptr<roadfighter::PlayerCar> Player;
        // Pointer to bullet
        std::shared_ptr<roadfighter::Bullet> Bullet;
        // Set with pointers to passing cars
        std::set<std::shared_ptr<PassingCar>> PassingCars;
        // Set with pointers to racing cars
        std::set<std::shared_ptr<RacingCar>> RaceCars;
        // Pointer to factory
        std::shared_ptr<roadfighter::AbstractFactory> factory;
        // Pointer to ScoreObserver
        std::shared_ptr<roadfighter::ScoreObserver> score;

public:
        int getDistance() const;
        int getFinish() const;
        int getSpeed() const;
        unsigned int getA_collisions() const;
        const std::shared_ptr<PlayerCar>& getPlayer() const;
        const std::set<std::shared_ptr<RacingCar>>& getRaceCars() const;
        /**
         * Links the Observer to the world class
         * @param score
         */
        void attach(std::shared_ptr<roadfighter::ScoreObserver>& score);
        /**
         * Returns tuple with collision results, one for each side (left or right)
         * @param ent1
         * @param ent2
         * @return
         */
        std::tuple<bool, bool> entityCollision(std::shared_ptr<roadfighter::Entity> ent1,
                                               std::shared_ptr<roadfighter::Entity> ent2);
        /**
         * Runs game, calls run from all entities
         */
        void run() override;
        /**
         * Creates random event, can do nothing
         */
        void randomEvent();
        /**
         * Resets all the input bools
         */
        void clearInput();
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_WORLD_H
