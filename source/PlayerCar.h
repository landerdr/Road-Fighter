//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H


#include "Entity.h"

class PlayerCar : public Entity {
    unsigned int amountBullets = 16;
    unsigned int maxBullets = 64;
public:
    unsigned int xPos = 300;
    unsigned int move = 0;

    void run();
};


#endif //ROAD_FIGHTER_PLAYERCAR_H
