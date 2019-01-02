//
// Created by lander on 12/22/18.
//

#include "Transformation.h"

std::shared_ptr<Transformation> Transformation::m_pTransformation = nullptr;

Transformation::Transformation() {}
Transformation::~Transformation() {}

std::shared_ptr<Transformation> Transformation::Instance() {
    if (m_pTransformation == nullptr) {
        m_pTransformation = std::shared_ptr<Transformation>(new Transformation);
    }
    return m_pTransformation;
}

void Transformation::setSize(unsigned int ix, unsigned int iy) {
    x = ix;
    y = iy;
}

int Transformation::transX(float fx) {
    // Hardcoded to use -4 : 4
    return static_cast<int> ((fx + 4) * (x/8.0));
}

int Transformation::transY(float fy) {
    // Hardcoded to use -3 : 3
    return static_cast<int> ((fy + 3) * (y/6.0));
}
