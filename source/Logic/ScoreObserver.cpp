//
// Created by lander on 18.01.19.
//

#include "ScoreObserver.h"

#include <utility>

RoadFighter::ScoreObserver::ScoreObserver(std::shared_ptr<RoadFighter::World> subject) : subject(std::move(subject)) {}

int RoadFighter::ScoreObserver::getScore() const { return score; }

void RoadFighter::ScoreObserver::update()
{
        int placementScore = 0;
        for (auto& c : subject->getRaceCars()) {
                // Checks if player is further on screen than other racecars
                if (c->getUpperY() > subject->getPlayer()->getUpperY()) {
                        placementScore += 5000;
                }
        }
        score = static_cast<int>(subject->getDistance() + placementScore - subject->getA_collisions() * 500);
        score = std::max(score, 0);
}
