//
// Created by lander on 12/10/18.
//

#include "Entity.h"

double roadfighter::Entity::getLeftX() { return c_x - r_w; }

double roadfighter::Entity::getRightX() { return c_x + r_w; }

double roadfighter::Entity::getUpperY() { return c_y + r_h; }

double roadfighter::Entity::getLowerY() { return c_y - r_h; }

void roadfighter::Entity::draw() {}

void roadfighter::Entity::run() {}

double roadfighter::Entity::getR_w() const { return r_w; }

double roadfighter::Entity::getR_h() const { return r_h; }

double roadfighter::Entity::getC_x() const { return c_x; }

double roadfighter::Entity::getC_y() const { return c_y; }
