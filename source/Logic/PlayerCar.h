//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H


#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public Entity {
    public:
        unsigned int amountBullets = 0;
        unsigned int maxBullets = 8;

        // Controls
        bool m_left = false;
        bool m_right = false;
    public:
        void run() override;
        void moveleft();
        void moveright();
    };
}



#endif //ROAD_FIGHTER_PLAYERCAR_H
