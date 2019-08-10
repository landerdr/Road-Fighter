//
// Created by lander on 12/10/18.
//

#include "PlayerCar.h"

void RoadFighter::PlayerCar::run()
{
        if (m_left) {
                moveleft();
                m_left = false;
        }
        if (m_right) {
                moveright();
                m_right = false;
        }
}

void RoadFighter::PlayerCar::moveleft()
{
        if (getLeftX() > -1.5) {
                c_x -= (0.00005 * playerspeed);
        }
}

void RoadFighter::PlayerCar::moveright()
{
        if (getRightX() < 0.5) {
                c_x += (0.00005 * playerspeed);
        }
}

void RoadFighter::PlayerCar::setM_left(bool m_left) { PlayerCar::m_left = m_left; }

void RoadFighter::PlayerCar::setM_right(bool m_right) { PlayerCar::m_right = m_right; }

void RoadFighter::PlayerCar::setPlayerspeed(int playerspeed) { PlayerCar::playerspeed = playerspeed; }
