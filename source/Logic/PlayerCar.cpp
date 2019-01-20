//
// Created by lander on 12/10/18.
//

#include "PlayerCar.h"

void roadfighter::PlayerCar::run() {
    if (m_left) {
        moveleft();
        m_left = false;
    }
    if (m_right) {
        moveright();
        m_right = false;
    }

}

void roadfighter::PlayerCar::moveleft() {
    if (getLeftX() > -1.5) {
        c_x -= 0.02;
    }
}

void roadfighter::PlayerCar::moveright() {
    if (getRightX() < 0.5) {
        c_x += 0.02;
    }
}

void roadfighter::PlayerCar::setM_left(bool m_left) {
    PlayerCar::m_left = m_left;
}

void roadfighter::PlayerCar::setM_right(bool m_right) {
    PlayerCar::m_right = m_right;
}
