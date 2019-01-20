//
// Created by lander on 12/10/18.
//

#include "Entity.h"

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

float roadfighter::Entity::getR_w() const {
    return r_w;
}

float roadfighter::Entity::getR_h() const {
    return r_h;
}

