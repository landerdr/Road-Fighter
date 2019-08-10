//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_BULLET_H
#define ROAD_FIGHTER_BULLET_H

#include "Entity.h"

namespace RoadFighter {
class Bullet : public Entity
{
public:
        void run(int speed);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_BULLET_H
