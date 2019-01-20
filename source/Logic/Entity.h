//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H

#include <memory>
#include <string>

namespace roadfighter {
    class Entity {
    protected:
        // Center x position
        float c_x = 0;
        // Center y position
        float c_y = 0;
        // Half width of sprite
        float r_w = 0;
        // Half length of sprite
        float r_h = 0;

    public:
        float getC_x() const;

        float getC_y() const;

        float getR_w() const;

        float getR_h() const;

        float getLeftX();
        float getRightX();
        float getUpperY();
        float getLowerY();

        virtual void draw();
        virtual void run();
    };
}



#endif //ROAD_FIGHTER_ENTITY_H
