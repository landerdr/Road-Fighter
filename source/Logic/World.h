//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_WORLD_H
#define ROAD_FIGHTER_WORLD_H


#include <set>
#include "Entity.h"
#include "PlayerCar.h"

namespace roadfighter {
    class World : public Entity {
        std::set<std::shared_ptr<roadfighter::Entity>> Entities;
        std::shared_ptr<roadfighter::Entity> player;

    public:
        World();



        bool entityCollision(std::shared_ptr<roadfighter::Entity> ent1, std::shared_ptr<roadfighter::Entity> ent2);
    };
}



#endif //ROAD_FIGHTER_WORLD_H
