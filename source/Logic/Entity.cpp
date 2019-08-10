//
// Created by lander on 12/10/18.
//

#include "Entity.h"

double RoadFighter::Entity::getLeftX() { return c_x - r_w; }

double RoadFighter::Entity::getRightX() { return c_x + r_w; }

double RoadFighter::Entity::getUpperY() { return c_y - r_h; }

double RoadFighter::Entity::getLowerY() { return c_y + r_h; }

void RoadFighter::Entity::draw() {}

void RoadFighter::Entity::run() {}

double RoadFighter::Entity::getR_w() const { return r_w; }

double RoadFighter::Entity::getR_h() const { return r_h; }

double RoadFighter::Entity::getC_x() const { return c_x; }

double RoadFighter::Entity::getC_y() const { return c_y; }
