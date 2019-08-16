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
        /**
         * Sets move left bool, will make car move to the left if run is called
         * @param m_left
         */
        void setM_left(bool m_left);
        /**
         * Sets move right bool, will make car move to the right if run is called
         * @param m_right
         */
        void setM_right(bool m_right);
        /**
         * Updates player speed
         * @param playerspeed
         */
        void setPlayerspeed(int playerspeed);
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_PLAYERCAR_H
