//
// Created by lander on 12/10/18.
//

#include "Bullet.h"

void RoadFighter::Bullet::run(int speed)
{
        c_y -= (static_cast<int>(Configuration::Instance()->getBulletSpeed()) - speed) / 4000.0;
}
