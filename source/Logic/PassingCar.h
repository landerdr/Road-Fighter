//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H


#include "Entity.h"

namespace roadfighter {
    class PassingCar : public Entity {
    protected:
        int type = 0;
    public:
        void run(int speed);
        int getType() const;
    };
}



#endif //ROAD_FIGHTER_PASSINGCAR_H
