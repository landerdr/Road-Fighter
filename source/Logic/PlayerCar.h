//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H

#include "Entity.h"

namespace RoadFighter {
class PlayerCar : public Entity
{
protected:
        // Controls
        bool m_left = false;
        bool m_right = false;

        int playerspeed = 0;

public:
        /**
         * Calculates virtual position
         */
        void run() override;
        /**
         * Moves player left if possible
         */
        void moveleft();
        /**
         * Moves player right if possible
         */
        void moveright();

        void setM_left(bool m_left);
        void setM_right(bool m_right);
        void setPlayerspeed(int playerspeed);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_PLAYERCAR_H
