//
// Created by lander on 12/22/18.
//

#include "Random.h"

std::shared_ptr<RoadFighter::Random> RoadFighter::Random::m_pRandom = nullptr;

RoadFighter::Random::Random() { srand(1998); }

std::shared_ptr<RoadFighter::Random> RoadFighter::Random::Instance()
{
        if (m_pRandom == nullptr) {
                m_pRandom = std::shared_ptr<RoadFighter::Random>(new RoadFighter::Random);
        }
        return m_pRandom;
}

int RoadFighter::Random::getInt() { return rand(); }
