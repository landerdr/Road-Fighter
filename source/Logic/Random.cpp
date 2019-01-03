//
// Created by lander on 12/22/18.
//

#include <memory>
#include "Random.h"

std::shared_ptr<roadfighter::Random> roadfighter::Random::m_pRandom = nullptr;

roadfighter::Random::Random() {
    srand(1998);
}
roadfighter::Random::~Random() {}

std::shared_ptr<roadfighter::Random> roadfighter::Random::Instance() {
    if (m_pRandom == nullptr) {
        m_pRandom = std::shared_ptr<roadfighter::Random>(new roadfighter::Random);
    }
    return m_pRandom;
}

int roadfighter::Random::getInt(){
    return rand();
}
