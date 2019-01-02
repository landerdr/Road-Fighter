//
// Created by lander on 12/22/18.
//

#include "Random.h"

Random* Random::m_pRandom = nullptr;

Random::Random() {}
Random::~Random() {}

Random *Random::Instance() {
    if (m_pRandom == nullptr) {
        m_pRandom = new Random;
    }
    return m_pRandom;
}
