//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H


#include "Entity.h"

namespace roadfighter {
    class PassingCar : public Entity {
    public:
        void run(int speed);
    };
}



#endif //ROAD_FIGHTER_PASSINGCAR_H
