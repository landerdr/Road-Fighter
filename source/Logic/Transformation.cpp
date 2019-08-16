//
// Created by lander on 12/22/18.
//

#include "Transformation.h"

std::shared_ptr<RoadFighter::Transformation> RoadFighter::Transformation::m_pTransformation = nullptr;

std::shared_ptr<RoadFighter::Transformation> RoadFighter::Transformation::Instance()
{
        if (m_pTransformation == nullptr) {
                m_pTransformation = std::make_shared<RoadFighter::Transformation>();
        }
        return m_pTransformation;
}

void RoadFighter::Transformation::setSize(unsigned int ix, unsigned int iy)
{
        x = ix;
        y = iy;
}

float RoadFighter::Transformation::transX(double fx)
{
        /**
         * Hardcoded to use -4 : 4
         * changes fx to 0 : 1 * screensize
         */
        return static_cast<float>((fx + 4) * (x / 8.0));
}

float RoadFighter::Transformation::transY(double fy)
{
        /**
         * Hardcoded to use -3 : 3
         * changes fy to 0 : 1 * screensize
         */
        return static_cast<float>((fy + 3) * (y / 6.0));
}

float RoadFighter::Transformation::getScaleX()
{
        if (x && y) {
                // 100px width of background, 2 because only half of window is used for background
                return static_cast<float>(x) / 200;
        }
        return 0;
}

float RoadFighter::Transformation::getScaleY()
{
        if (x && y) {
                // 50px length of background, 3 stripes on screen
                return static_cast<float>(y) / 150;
        }
        return 0;
}
