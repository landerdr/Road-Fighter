//
// Created by lander on 12/10/18.
//

#include "PlayerCar.h"

roadfighter::PlayerCar::PlayerCar() {
    r_w = 0.05;
    r_h = 0.033333;
    c_x = 0;
    c_y = 2;
}

void roadfighter::PlayerCar::run() {
    if (m_left && c_x - r_w > -1.5) {
        c_x -= 0.02;
        m_left = false;
    }
    if (m_right && c_x + r_w < 0.2) {
        c_x += 0.02;
        m_right = false;
    }

}

float roadfighter::PlayerCar::getUpperCorner_X() {
    return c_x - r_w;
}

float roadfighter::PlayerCar::getUpperCorner_Y() {
    return c_y + r_h;
}
