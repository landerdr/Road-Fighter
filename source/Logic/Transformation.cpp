//
// Created by lander on 12/22/18.
//

#include "Transformation.h"

std::shared_ptr<roadfighter::Transformation> roadfighter::Transformation::m_pTransformation = nullptr;

roadfighter::Transformation::Transformation() {}
roadfighter::Transformation::~Transformation() {}

std::shared_ptr<roadfighter::Transformation> roadfighter::Transformation::Instance() {
    if (m_pTransformation == nullptr) {
        m_pTransformation = std::shared_ptr<roadfighter::Transformation>(new roadfighter::Transformation);
    }
    return m_pTransformation;
}

void roadfighter::Transformation::setSize(unsigned int ix, unsigned int iy) {
    x = ix;
    y = iy;
}

int roadfighter::Transformation::transX(double fx) {
    // Hardcoded to use -4 : 4
    return static_cast<int> ((fx + 4) * (x/8.0));
}

int roadfighter::Transformation::transY(double fy) {
    // Hardcoded to use -3 : 3
    return static_cast<int> ((fy + 3) * (y/6.0));
}

float roadfighter::Transformation::getScaleX() {
    if (x && y) {
        return static_cast<float>(x)/200;
    }
    return 0;
}

float roadfighter::Transformation::getScaleY() {
    if (x && y) {
        return static_cast<float>(y)/150;
    }
    return 0;
}
