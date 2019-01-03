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
        std::set<Entity*> Entities;
        PlayerCar* player;

    public:

        bool entityCollision(Entity* ent1, Entity* ent2);
    };
}



#endif //ROAD_FIGHTER_WORLD_H
