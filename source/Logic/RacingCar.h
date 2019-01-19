//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_RACINGCAR_H
#define ROAD_FIGHTER_RACINGCAR_H


#include "Entity.h"

namespace roadfighter {
    class RacingCar : public Entity {
    protected:
        int speed = 0;
    public:
        void run() override;
        void moveleft();
        void moveright();
    };
}



#endif //ROAD_FIGHTER_RACINGCAR_H
