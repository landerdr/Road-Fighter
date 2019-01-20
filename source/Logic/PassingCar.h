//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PASSINGCAR_H
#define ROAD_FIGHTER_PASSINGCAR_H

#include "Entity.h"

namespace roadfighter {
class PassingCar : public Entity
{
protected:
        int type = 0;

public:
        /**
         * Calculates virtual position on screen depending on playerspeed
         * @param speed
         */
        void run(int speed);

        int getType() const;
};
} // namespace roadfighter

#endif // ROAD_FIGHTER_PASSINGCAR_H
