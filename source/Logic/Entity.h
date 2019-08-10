//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include <algorithm>
#include <memory>
#include <string>
#include "../Logic/Configuration.h"
#include "../Logic/Transformation.h"

namespace RoadFighter {
class Entity
{
protected:
        // Center x position
        double c_x = 0;
        // Center y position
        double c_y = 0;
        // Half width of sprite
        double r_w = 0;
        // Half length of sprite
        double r_h = 0;

public:
        double getC_x() const;

        double getC_y() const;

        double getR_w() const;

        double getR_h() const;

        /**
         * Calculates left x value
         * @return
         */
        double getLeftX();
        /**
         * Calculates right x value
         * @return
         */
        double getRightX();
        /**
         * Calculates top y value
         * @return
         */
        double getUpperY();
        /**
         * Calculates lower y value
         * @return
         */
        double getLowerY();

        virtual void draw();

        virtual void run();
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_ENTITY_H
