//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_ENTITY_H
#define ROAD_FIGHTER_ENTITY_H


#include <string>

class Entity {
protected:
    // Center x position
    float c_x;
    // Center y position
    float c_y;
    // Half width of sprite
    float r_w;
    // Half length of sprite
    float r_h;

public:
    Entity();
};


#endif //ROAD_FIGHTER_ENTITY_H
