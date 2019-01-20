//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_BULLET_H
#define ROAD_FIGHTER_BULLET_H

#include "Entity.h"

namespace roadfighter {
class Bullet : public Entity
{
public:
        void run() override;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_BULLET_H
