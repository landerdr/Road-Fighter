//
// Created by lander on 12/22/18.
//

#include "Transformation.h"

Transformation* Transformation::m_pTransformation = nullptr;

Transformation::Transformation() {}
Transformation::~Transformation() {}

Transformation *Transformation::Instance() {
    if (m_pTransformation == nullptr) {
        m_pTransformation = new Transformation;
    }
    return m_pTransformation;
}