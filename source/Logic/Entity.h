//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include "../Logic/Configuration.h"
#include "../Logic/Transformation.h"
#include <algorithm>
#include <memory>
#include <string>

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
        /**
         * Returns x center value
         * @return
         */
        double getC_x() const;
        /**
         * Returns y center value
         * @return
         */
        double getC_y() const;
        /**
         * Returns half of entity width
         * @return
         */
        double getR_w() const;
        /**
         * Returns half of entity height
         * @return
         */
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
        /**
         * Virtual entity draw
         */
        virtual void draw();
        /**
         * Virtual run for 1 tick
         */
        virtual void run();
};
} // namespace RoadFighter

#endif // ROAD_FIGHTER_ENTITY_H
