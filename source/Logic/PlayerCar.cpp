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
    if (m_left && getLeftX() > -1.5) {
        c_x -= 0.02;
        m_left = false;
    }
    if (m_right && getRightX() < 0.2) {
        c_x += 0.02;
        m_right = false;
    }

}
