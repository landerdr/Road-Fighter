//
// Created by lander on 12/22/18.
//

#include <memory>
#include "Random.h"

std::shared_ptr<Random> Random::m_pRandom = nullptr;

Random::Random() {}
Random::~Random() {}

std::shared_ptr<Random> Random::Instance() {
    if (m_pRandom == nullptr) {
        m_pRandom = std::shared_ptr<Random>(new Random);
    }
    return m_pRandom;
}
