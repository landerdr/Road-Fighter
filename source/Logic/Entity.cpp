//
// Created by lander on 12/10/18.
//

#include "Entity.h"

roadfighter::Entity::Entity() {}

float roadfighter::Entity::getLeftX() {
    return c_x - r_w;
}

float roadfighter::Entity::getRightX() {
    return c_x + r_w;
}

float roadfighter::Entity::getUpperY() {
    return c_y + r_h;
}

float roadfighter::Entity::getLowerY() {
    return c_y - r_h;
}

void roadfighter::Entity::draw() {}

void roadfighter::Entity::run() {}

