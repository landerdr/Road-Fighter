//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H


#include "Entity.h"

namespace roadfighter {
    class PlayerCar : public Entity {
    protected:
        // Controls
        bool m_left = false;
        bool m_right = false;
    public:
        void run() override;
        void moveleft();
        void moveright();
        void setM_left(bool m_left);
        void setM_right(bool m_right);

    };
}



#endif //ROAD_FIGHTER_PLAYERCAR_H
