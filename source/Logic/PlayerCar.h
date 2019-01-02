//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H


#include "Entity.h"

class PlayerCar : public Entity {
public:
    unsigned int amountBullets = 0;
    unsigned int maxBullets = 8;

    // Controls
    bool m_up = false;
    bool m_down = false;
    bool m_left = false;
    bool m_right = false;
public:
    PlayerCar();

    float getUpperCorner_X();
    float getUpperCorner_Y();

    void run();
};


#endif //ROAD_FIGHTER_PLAYERCAR_H
