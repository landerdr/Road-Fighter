//
// Created by lander on 12/10/18.
//

#include "PlayerCar.h"

void PlayerCar::run() {
    switch (move) {
        case 3: xPos -= 5;
                break;
        case 4: xPos += 5;
                break;
    }
}
