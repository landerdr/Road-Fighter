//
// Created by lander on 12/10/18.
//

#include "PlayerCar.h"

int MOVESPEED = 2;

void PlayerCar::run() {
    switch (move) {
        case 3: {
            if (xPos-MOVESPEED > 250) {
                xPos -= MOVESPEED;
            }
            break;
        }

        case 4: {
            if (xPos+MOVESPEED < 422) {
                xPos += MOVESPEED;
            }
            break;
        }

    }
    move = 0;

}
