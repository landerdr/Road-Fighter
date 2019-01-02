//
// Created by lander on 12/10/18.
//

#ifndef ROAD_FIGHTER_PLAYERCAR_H
#define ROAD_FIGHTER_PLAYERCAR_H


#include "Entity.h"

class PlayerCar : public Entity {
    unsigned int amountBullets = 0;
    unsigned int maxBullets = 8;

public:
    PlayerCar();

    void run();
};


#endif //ROAD_FIGHTER_PLAYERCAR_H
